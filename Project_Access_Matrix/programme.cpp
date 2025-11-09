#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>
#include <ctime> 

using namespace std;

// Глобальная матрица для доступа из всех функций
vector<string> users;
vector<string> objects;
vector<vector<string>> rights_matrix;

// Функция инициализации матрицы
void initializeMatrix() {
    srand(time(0));
    
    users = {"admin", "guest", "leb1", "leb2", "leb3"};
    objects = {"file1", "file2", "file3", "cd_drive", "printer"};
    
    // Создаем матрицу 5x5
    rights_matrix.resize(users.size(), vector<string>(objects.size()));
    
    // Заполняем правами
    for (int i = 0; i < users.size(); i++) {
        for (int j = 0; j < objects.size(); j++) {
            if (users[i] == "admin") {
                rights_matrix[i][j] = "Full";
            } else {
                int r = rand() % 8;
                switch(r) {
                    case 0: rights_matrix[i][j] = "Deny"; break;
                    case 1: rights_matrix[i][j] = "Read"; break;
                    case 2: rights_matrix[i][j] = "Write"; break;
                    case 3: rights_matrix[i][j] = "Grant"; break;
                    case 4: rights_matrix[i][j] = "Read+Write"; break;
                    case 5: rights_matrix[i][j] = "Read+Grant"; break;
                    case 6: rights_matrix[i][j] = "Write+Grant"; break;
                    case 7: rights_matrix[i][j] = "Full"; break;
                }
            }
        }
    }
}

// Функция проверки прав
bool hasPermission(string user, string object, string action) {
    // Находим индексы пользователя и объекта
    int user_index = -1, object_index = -1;
    
    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            user_index = i;
            break;
        }
    }
    
    for (int j = 0; j < objects.size(); j++) {
        if (objects[j] == object) {
            object_index = j;
            break;
        }
    }
    
    if (user_index == -1 || object_index == -1) {
        return false; // Пользователь или объект не найден
    }
    
    string rights = rights_matrix[user_index][object_index];
    
    // Проверяем права
    if (rights == "Full") return true;
    if (rights == "Deny") return false;
    
    if (action == "read") return rights.find("Read") != string::npos;
    if (action == "write") return rights.find("Write") != string::npos;
    if (action == "grant") return rights.find("Grant") != string::npos;
    
    return false;
}

void printLabTable() {
    cout << "\n=== ACCESS CONTROL MATRIX ===" << endl;
    
    // Находим максимальную длину имени пользователя
    int max_user_width = 15; // Минимальная ширина для "Object / Subject"
    for (const string& user : users) {
        if (user.length() > max_user_width) {
            max_user_width = user.length();
        }
    }
    max_user_width += 2; // Добавляем отступ
    
    // Находим максимальную длину прав
    int max_rights_width = 8; // Минимальная ширина
    for (int i = 0; i < users.size(); i++) {
        for (int j = 0; j < objects.size(); j++) {
            if (rights_matrix[i][j].length() > max_rights_width) {
                max_rights_width = rights_matrix[i][j].length();
            }
        }
    }
    max_rights_width += 2; // Добавляем отступ
    
    // Заголовок
    cout << left << setw(max_user_width) << "Object / Subject";
    for (const string& obj : objects) {
        cout << setw(max_rights_width) << obj;
    }
    cout << endl;
    
    // Разделитель
    int total_width = max_user_width + max_rights_width * objects.size();
    cout << string(total_width, '-') << endl;
    
    // Данные
    for (int i = 0; i < users.size(); i++) {
        cout << setw(max_user_width) << users[i];
        
        for (int j = 0; j < objects.size(); j++) {
            cout << setw(max_rights_width) << rights_matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//Функция чтения файла
void read(string n){
    ifstream file(n + ".txt");
    if (!file.is_open()) {
        cout << "Error: File " << n << ".txt not found!" << endl;
        return;
    }
    
    string line;
    int lineNumber = 1;

    while (getline(file, line)){
        cout << "Line " << to_string(lineNumber) << ": " << line << endl; 
        lineNumber++;
    }
    file.close();
}

//Функция записи файла
void write(string n, string add){
    ofstream file (n + ".txt", ios::app);

    if (file.is_open()){
        file << add << endl;
        file.close();
        cout << "Text successfully written to " << n << ".txt" << endl;
    } else {
        cout << "Error: Cannot open file " << n << ".txt" << endl;
    }
}

//Функция выдачи прав
void grant(string user, string file, string new_right){
    // Находим индексы user and file in matrix
    int user_index = -1, object_index = -1;
    
    for (int i = 0; i < users.size(); i++) {
        if (users[i] == user) {
            user_index = i;
            break;
        }
    }
    
    for (int j = 0; j < objects.size(); j++) {
        if (objects[j] == file) {
            object_index = j;
            break;
        }
    }

    rights_matrix[user_index][object_index] = rights_matrix[user_index][object_index] + "+" + new_right;
    cout << "Rights updated! ";
}

void execute(string file){
    if ((file == "cd_drive") | (file == "printer"))
        cout << "Device " + file + " have started a job!" << endl;
    else 
        cout << "It's a file, but should be a device!" << endl;
}

// Преобразует ввод пользователя в имя файла из матрицы
string getObjectName(string input) {
    if (input == "1") return "file1";
    if (input == "2") return "file2"; 
    if (input == "3") return "file3";
    if (input == "4") return "cd_drive";
    if (input == "5") return "printer";
    return input; // Если введено прямое имя
}

string getCommandName(string input) {
    if (input == "1") return "read";
    if (input == "2") return "write";
    if (input == "3") return "grant";
    if (input == "4") return "execute";
    if (input == "5") return "quit";
    if (input == "6") return "exit";
    return input;
 }

void programme(){
    string user;
    string numfile;
    string command;
    
    cout << "==Programme running==" << endl;
    while (true){
        cout << "Who are you? > ";
        cin >> user;
        
        // Проверяем существование пользователя
        bool user_exists = false;
        for (const string& u : users) {
            if (u == user) {
                user_exists = true;
                break;
            }
        }
        
        if (!user_exists) {
            cout << "Error: User '" << user << "' not found!" << endl;
            return;
        }
        cout << "You may: 1[read], 2[write], 3[grant], [4]execute, 5[quit], [6]exit." << endl;
        while (true){
            cout << "I'm waiting your commands > ";
            
            cin >> command;
            string command1 = getCommandName(command);
            if (command1 == "exit") {
                cout << "Goodbye!" << endl;
                return;
            }
            else if (command1 == "read"){
                cout << "Which file will we use? (1-5 or name) > ";
                cin >> numfile;
                string object_name = getObjectName(numfile);
                bool per = hasPermission(user, object_name, command1);
                if (per){
                    cout << "Access granted. Reading file..." << endl;
                    read(object_name);
                } else {
                    cout << "Access denied! No read permission for " << object_name << endl;
                }
            }
            else if (command1 == "write") {
                cout << "Which file will we use? (1-5 or name) > ";
                cin >> numfile;
                string object_name = getObjectName(numfile);
                bool per = hasPermission(user, object_name, command1);
                if (per) {
                    cout << "Enter text to write: ";
                    string text;
                    cin.ignore(); // Очищаем буфер
                    getline(cin, text);
                    write(object_name, text);
                } else {
                    cout << "Access denied! No write permission for " << object_name << endl;
                }
            }
            else if (command1 == "grant") {
                string user2;
                string numfile;
                string right;
                cout << "Which user will add right? > ";
                cin >> user2;
                cout << "Which file will add right? > ";
                cin >> numfile;
                cout << "Which right will add? > ";
                cin >> right;
                string object_name = getObjectName(numfile);
                bool per = hasPermission(user, object_name, command1);
                if (per){
                    grant(user2, numfile, right);
                    cout << endl;
                    printLabTable();
                } else {
                    cout << "Access denied! No grant permission for " << object_name << endl;
                }
            }
            else if(command1 == "execute"){
                string numfile;
                cout << "Which file will we execute? > ";
                cin >> numfile;
                string object_name = getObjectName(numfile);
                bool per = hasPermission(user, object_name, command1);
                if (per){
                    execute(object_name);
                } else {
                    cout << "Access denied! No grant permission for " << object_name << endl;
                }
            }
            else if (command1 == "quit" || command1 == "5"){
                cout << "Signing out!" << endl;
                break;
            }
            else {
                cout << "Unknown command: " << command1 << endl;
            }
        }
    }
}

int main() {
    initializeMatrix();
    printLabTable();
    
    programme();

    return 0;
}
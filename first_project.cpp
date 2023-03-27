#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int button;
struct sold {
    string name;
    int quantity;
    string date;
};
void inputCheck(int& a, int b, int c){
    while (!(cin >> a) || a < b || a > c) {
        cin.clear(); // clear the error flags
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the input
        if(b == 0 and c == 0){
            cout << "Для выхода в главное меню введите 0:>>";
        }
        else {
            cout << "Произошла ошибка. Введите число от " << b << " до " << c << endl;
        }
    }
}
void showMenuSales(){
    cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
    cout <<"1.Показать весь список материалов для продажи" << endl;
    cout <<"2.Искать материал" << endl;
    cout << "3.Показать отчет по продаже" << endl << "4.Выполнить продажу оборудований" << endl;
    cout << "5.Сделать заказ отсутствующего товара" << endl << "6.Удалить заказ" << endl << "7.Выход" << endl;
    cout << "8.Промышленное производство" << endl;
    cout << "Выбор меню:>>";
}
void showMenuDelivery(){
    string Deliveryman [] = {
        "1.Показать список материалов для доставки",
        "2.Показать доставленные заказы",
        "3.Доставить заказ",
        "4.Показать количество доставленных оборудований",
        "5.Показать количество заказанных товаров",
        "6.Показать мой заработок",
        "7.Выход",
        "8.Инструкции"
    };
    for(auto now: Deliveryman){
        cout << now << endl;
    }
}
void showMenuProvider(){
    string Provider [] = {
        "1.Показать список товаров для поставки",
        "2.Показать количество поставляемого материала",
        "3.Показать материал с самым большим количеством заказов для доставки",
        "4.Показать материал с самым меньшим количеством заказов для доставки",
        "5.Выход",
        "6.Инструкции"
    };
    for(auto now: Provider){
        cout << now << endl;
    }
}
void goToMenu(){
    cout << endl << "0 - К главному меню" << endl;
    inputCheck(button, 0, 0);
}
void signInAndCheck(int c){
    string a, b;
    while(true){
        cout << "Логин:>>";
        cin >> a;
        cout << "Пароль:>>";
        cin >> b;
        if(a == "d" and b == "d123" and c == 1 or a == "s" and b == "s123" and c == 2 or a == "p" and b == "p123" and c == 3){
            break;
        }
        else {
            cout << "Неверный логин или пароль. Попробуйте заново:" << endl;
        }
    }
}
void showFileContent(const string& filename, string d){
    string sales;
    ifstream ReadFile(filename);
    if(ReadFile.peek() == std::ifstream::traits_type::eof()){
        cout << d << endl;
    }
    else{
        while(getline (ReadFile, sales)){
            cout << sales << endl;
        }
    }
    ReadFile.close();
}
void searchFromFile(const string& filename){
    int subMenuNumber;
    string nameSearch, dateSearch;
    while(true){
        cout << "Выберите: каким способом хотите искать:" << endl << "1.По названию" << endl << "2.По дате" << endl;
        inputCheck(subMenuNumber, 1, 2);
        int q = 0;
        if(subMenuNumber == 1){
            cout << "Напишите название материала для поиска:>>";
            cin >> nameSearch;
            cout << "Результаты поиска:" << endl;
            ifstream ReadFile(filename);
            if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                cout << "Нет товаров для продажи." << endl;
                break;
            }
            else {
                string line;
                while (getline(ReadFile, line)) {
                    if (line.find(nameSearch) != string::npos) {
                        q++;
                        cout << line << endl;
                    }
                }
    
                // Переход к главному меню
                if(q != 0) {
                    cout << endl << "0 - К главному меню" << endl;
                    inputCheck(button, 0, 0);
                    break;
                }
                else if(q == 0){
                    cout << "Не удалось найти товар с таким названием..." << endl;
                    cout << "Попробуйте ввести заново:>>";
                }
            }
            cout << endl << "0 - К главному меню" << endl;
            inputCheck(button, 0, 0);
            ReadFile.close();
        }
        else if(subMenuNumber == 2){
            q = 0;
            cout << endl << "Напишите дату для поиска:>>";
            dateSearch: cin >> dateSearch;
            cout << "Результаты поиска:" << endl;
            string line;
            ifstream ReadFile("sales.txt");
            if(ReadFile.peek() == std::ifstream::traits_type::eof()){
                cout << "Нет товаров для продажи." << endl;
                break;
            }
            else{
                while (getline(ReadFile, line)) {
                    if (line.find(dateSearch) != string::npos) {
                        q++;
                        cout << line << endl;
                    }
                }
                
                // Переход к главному меню
                if(q != 0){
                    cout << endl << "0 - К главному меню" << endl;
                    inputCheck(button, 0, 0);
                    break;
                }
                else if(q == 0){
                    cout << "Не удалось найти товар с такой датой..." << endl;
                    cout << "Попробуйте ввести заново:>>";
                    goto dateSearch;
                }
            }
            cout << endl << "0 - К главному меню" << endl;
            inputCheck(button, 0, 0);
            ReadFile.close();
        }
    }
}
void moveElement(const string& filename1, const string& filename2) { 
    string sales;
    ifstream ReadFile(filename1); 
    if(ReadFile.peek() == std::ifstream::traits_type::eof()){
        cout << endl;
    }
    else{
        cout << "Пожалуйста напишите название материала, который вы бы хотели продать:>>"; 
        string elementToMove; 
        cin >> elementToMove; 
     
        string lineSell; 
        string lineSold; 
        bool elementFound = false; 
        ifstream sale(filename1); 
        ofstream saletemp("saletemp.txt"); 
        ifstream sold(filename2); 
        ofstream soldtemp("soldtemp.txt"); 
        while (getline(sold, lineSold)) { 
            soldtemp << lineSold << endl; 
        } 
        while (getline(sale, lineSell)) { 
            if (lineSell.find(elementToMove) != string::npos) { 
                elementFound = true; 
                soldtemp << lineSell << endl; 
            } else { 
                saletemp << lineSell << endl; 
            } 
        } 
        sale.close(); 
        saletemp.close(); 
        sold.close(); 
        soldtemp.close(); 
        remove(filename1.c_str()); 
        rename("saletemp.txt", filename1.c_str()); 
        remove(filename2.c_str()); 
        rename("soldtemp.txt", filename2.c_str()); 
     
        if (elementFound) { 
            cout << "Ваш запрос принят." << endl; 
        } else { 
            cout << "Запас данного материала закончился, пожалуйста сделайте заказ на поставку!" << endl; 
        } 
    }
    ReadFile.close();
    goToMenu();
}
int endProgram(){
    cout << "Программа завершена, мы будем рады вашему возвращению!";
    exit(0);
}
void deleteElement(const string& filename){
    string sold;
    ifstream ReadFile(filename);
    if(ReadFile.peek() == std::ifstream::traits_type::eof()){
        cout << endl;
    }
    else{
        string DeleteOrder;
        cout << "Напишите название товара заказа который вы бы хотели удалить?>>";
        cin >> DeleteOrder;
        string LineDel;
        bool elementFound = false; 
        ifstream ReadFiledelOrder(filename);
        ofstream DeleteOrdertemp("deltempsold.txt");
        while(getline (ReadFiledelOrder, LineDel)){
            if(LineDel.find(DeleteOrder) != string::npos){
                elementFound = true; 
                continue;
            }
            else{
                DeleteOrdertemp << LineDel << endl;
            }
        }
        ReadFiledelOrder.close();
        DeleteOrdertemp.close();
        remove(filename.c_str());
        rename("deltempsold.txt", filename.c_str());
        if (elementFound) { 
            cout << "Ваш запрос принят." << endl; 
        } else { 
            cout << "Запас данного материала закончился, пожалуйста сделайте заказ на поставку!" << endl; 
        } 
    }
    ReadFile.close();
    goToMenu();
}
void numberOfMaterials(const string& filename, string d, string c){
    int count = 0;
        string line;
        ifstream ReadDelivered(filename);
        if (ReadDelivered.peek() == ifstream::traits_type::eof()) {
            cout << d << endl;
        }
        else {
            while(getline(ReadDelivered, line)){
                count++;
            }
            cout << "Количество " << c << " товаров: ";
            cout << count;
        }
        ReadDelivered.close();
}
void salaryCounter(const string & filename, string d){
    int stake = 1000;
    string line;
    ifstream ReadFile(filename);
    if (ReadFile.peek() == ifstream::traits_type::eof()) {
        cout << d << endl;
    } else {
        while(getline (ReadFile, line)){
            cout << line << " - " << stake << "с" << endl;
        }
        int count = 0;
        string lineCount;
        ifstream ReadDelivered(filename);
        while(getline(ReadDelivered, lineCount)){
            count++;
        }
        cout << "Ваш заработок: " << count * stake << "сомов";
        ReadDelivered.close();
    }
    ReadFile.close();
}
void maxMinOfMaterials(int menuNumber){
    ifstream ReadSold("sold.txt");
    if (ReadSold.peek() == ifstream::traits_type::eof()) {
        cout << "Нет заказов." << endl;
    } else {
        vector<sold> Sold;
        string name;
        int quantity;
        string date;
    
        while (ReadSold >> name >> quantity >> date) {
            sold materials;
            materials.name = name;
            materials.quantity = quantity;
            materials.date = date;
            Sold.push_back(materials);
        }
        if (Sold.empty()) {
            cout << "Нет никаких заказов." << endl;
            goToMenu();
        }
        
        if (menuNumber == 3) {
            int MaterialWithMaxOrders = INT_MIN;
            for (auto now : Sold) {
                if (now.quantity > MaterialWithMaxOrders) {
                    MaterialWithMaxOrders = now.quantity;
                }
            }
            vector <string> MaterialsWithMaxOrders;
            for (auto now : Sold) {
                if (now.quantity == MaterialWithMaxOrders) {
                    MaterialsWithMaxOrders.push_back(now.name);
                }
            }
            cout << "Результаты: ";
            for (auto now : MaterialsWithMaxOrders) {
                cout << now << endl;
            }
        }
        else if (menuNumber == 4) {
            int MaterialWithMinOrders = INT_MAX;
            for (auto now : Sold) {
                if (now.quantity < MaterialWithMinOrders) {
                    MaterialWithMinOrders = now.quantity;
                }
            }
            vector <string> MaterialsWithMinOrders;
            for (auto now : Sold) {
                if (now.quantity == MaterialWithMinOrders) {
                    MaterialsWithMinOrders.push_back(now.name);
                }
            }
            cout << "Результаты:  ";
            for (auto now : MaterialsWithMinOrders) {
                cout << now << endl;
            }
        }
    }
    ReadSold.close();
    goToMenu();
}
void showInstructions(){
    cout << "Инструкция:" << endl;
    showFileContent("instructions.txt", " ");
    goToMenu();
}
int main(){
    int accountType, menuNumber;
    cout << "Для запуска программы, пожалуйста введите тип аккаунта:>>";
    cout << endl << "1. Delivery man" << endl << "2. Salesman" << endl << "3. Provider" << endl;
    //Вводится тип аккаунта
    inputCheck(accountType, 1, 3);
    const int saleMan = 2, deliveryMan = 1, providerMan = 3;
    if(accountType == deliveryMan or accountType == saleMan or accountType == providerMan){
        if(accountType == deliveryMan){
            cout << "Вы выбрали тип аккаунта: доставщик." << endl;
        }
        else if(accountType == saleMan){
            cout << "Вы выбрали тип аккаунта: продавец." << endl;
        }
        else if(accountType == providerMan){
            cout << "Вы выбрали тип аккаунта: поставщик." << endl;
        }
        
        cout << "Пожалуйста, введите ваш логин и пароль:>>" << endl;
        signInAndCheck(accountType);
        //Меню для аккаунта продавца
        if(accountType == saleMan){
            cout <<"Приветствую, дорогой Продавец!" << endl;
            while(true){
                showMenuSales();
                inputCheck(menuNumber, 1, 8);
                switch(menuNumber) { 
                    case 1: 
                        showFileContent("sales.txt", "Нет товаров для продажи."); 
                        goToMenu(); 
                        break; 
                    case 2: 
                        searchFromFile("sales.txt"); 
                        break; 
                    case 3: 
                        showFileContent("sold.txt", "Нет проданных товаров."); 
                        goToMenu(); 
                        break; 
                    case 4: 
                        showFileContent("sales.txt", "Нет товаров для продажи."); 
                        moveElement("sales.txt", "sold.txt"); 
                        break; 
                    case 5: 
                        showFileContent("nomaterials.txt", "Нет отсутствующих товаров."); 
                        moveElement("nomaterials.txt", "need_materials.txt"); 
                        break; 
                    case 6: 
                        showFileContent("sold.txt", "Нет заказов."); 
                        deleteElement("sold.txt"); 
                        break; 
                    case 7: 
                        endProgram(); 
                        break; 
                    case 8: 
                        showInstructions(); 
                        break; 
                    default: 
                        // Handle invalid menu number 
                        break; 
                }
            }
        }
        
        //Меню для аккаунта доставщика
        else if(accountType == deliveryMan){
            cout << "Приветствую, дорогой Доставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
            while(true){
                showMenuDelivery();
                cout << "Выбор меню:>>";
                inputCheck(menuNumber, 1, 8);
                switch(menuNumber) { 
                    case 1: 
                        showFileContent("sold.txt", "Нет проданных товаров."); 
                        goToMenu(); 
                        break; 
                    case 2: 
                        showFileContent("delivered.txt", "Нет доставленных товаров."); 
                        goToMenu(); 
                        break; 
                    case 3: 
                        showFileContent("sold.txt", "Нет проданных товаров."); 
                        moveElement("sold.txt", "delivered.txt"); 
                        break; 
                    case 4: 
                        numberOfMaterials("delivered.txt", "Нет доставленных товаров.", "доставленнных"); 
                        goToMenu(); 
                        break; 
                    case 5: 
                        numberOfMaterials("sold.txt", "Нет проданных товаров.", "проданных"); 
                        goToMenu(); 
                        break; 
                    case 6: 
                        salaryCounter("delivered.txt", "У вас нет доставленных товаров."); 
                        goToMenu(); 
                        break; 
                    case 7: 
                        endProgram(); 
                        break; 
                    case 8: 
                        showInstructions(); 
                        break; 
                    default: 
                        break; 
                }
            }
        }
        
        //Меню для аккаунта поставщика
        else if(accountType == providerMan){
            cout << "Приветствую, дорогой Поставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 5:" << endl;
            while(true){
                showMenuProvider();
                cout << "Выбор меню:>>";
                inputCheck(menuNumber, 1, 6);
                switch(menuNumber) { 
                    case 1: 
                        showFileContent("need_materials.txt", "Нет товаров для поставки."); 
                        goToMenu(); 
                        break; 
                    case 2: 
                        numberOfMaterials("need_materials.txt", "Нет товаров для поставки.", "поставляемого"); 
                        goToMenu(); 
                        break; 
                    case 3: 
                    case 4: 
                        maxMinOfMaterials(menuNumber); 
                        break; 
                    case 5: 
                        endProgram(); 
                        break; 
                    case 6: 
                        showInstructions(); 
                        break; 
                    default: 
                        break; 
                }
            }
        }
        
    }
    return 0;
}
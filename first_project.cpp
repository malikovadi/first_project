#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Sales {
    string name;
    string date;
};
struct Sold {
    string name;
    string date;
};
int main() {
    Sales sales[3];
    sales[0].name = "Хлопок";
    sales[1].name = "Лен";
    sales[2].name = "Шерсть";
    sales[0].date = "01/01/2022";
    sales[1].date = "02/02/2022";
    sales[2].date = "03/03/2022";
    Sold sold[3];
    sold[0].name = "Полиэстер";
    sold[1].name = "Нейлон";
    sold[2].name = "Акрил";
    sold[0].date = "04/04/2022";
    sold[1].date = "05/05/2022";
    sold[2].date = "06/06/2022";
    string username, password, nameSearch, dateSearch;
    int accountType, menuNumber, submenuNumber, button;
start: cout << "Для запуска программы, пожалуйста введите тип аккаунта:>>";
    cout << endl << "1. Delivery man" << endl << "2. Salesman" << endl << "3. Provider" << endl;
    //Вводится тип аккаунта
    cin >> accountType;
    if (accountType == 1 or accountType == 2 or accountType == 3) {
        if (accountType == 1) {
            cout << "Вы выбрали тип аккаунта: доставщик." << endl;
        }
        else if (accountType == 2) {
            cout << "Вы выбрали тип аккаунта: продавец." << endl;
        }
        else if (accountType == 3) {
            cout << "Вы выбрали тип аккаунта: поставщик." << endl;
        }
        //Вводится логин и пароль для авторизации
        cout << "Пожалуйста, введите ваш логин и пароль:>>" << endl;
    sign: cout << "Логин:>>";
        cin >> username;
        cout << "Пароль:>>";
        cin >> password;
        //Меню для аккаунта продавца
        if (username == "s" and password == "s123") {
            cout << "Приветствую, дорогой Продавец!" << endl;
        menu: cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
            cout << "1.Показать весь список материалов для продажи" << endl;
            cout << "2.Искать материал" << endl;
            cout << "3.Показать отчет по продаже" << endl << "4.Выполнить продажу оборудований" << endl;
            cout << "5.Сделать заказ отсутствующего товара" << endl << "6.Удалить заказ" << endl << "7.Выход" << endl;
            cout << "8.Промышленное производство" << endl;
            cout << "Выбор меню:>>";
            cin >> menuNumber;
            if (menuNumber == 1) {
                string sales;
                ifstream ReadFile("sales.txt");
                while (getline(ReadFile, sales)) {
                    cout << sales << endl;
                }
                ReadFile.close();
                cout << "0 - К главному меню" << endl;
                cin >> button;
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 2) {
                cout << "Выберите: каким способом хотите искать:" << endl << "1.По названию" << endl << "2.По дате" << endl;
                cin >> submenuNumber;
                int q = 0;
                if (submenuNumber == 1) {
                    cout << "Напишите название материала для поиска:>>";
                search: cin >> nameSearch;
                    cout << "Результаты поиска:" << endl;
                    ifstream ReadFile("sales.txt");
                    string line;
                    while (getline(ReadFile, line)) {
                        if (line.find(nameSearch) != string::npos) {
                            q++;
                            cout << line << endl;
                        }
                    }
                    ReadFile.close();
                    // Переход к главному меню
                    if (q != 0) {
                        cout << endl << "0 - К главному меню" << endl;
                        cin >> button;
                        if (button == 0) {
                            goto menu;
                        }
                    }
                    if (q == 0) {
                        cout << "Не удалось найти товар с таким названием..." << endl;
                        cout << "Попробуйте ввести заново:>>";
                        goto search;
                        cout << endl << "0 - К главному меню" << endl;
                        cin >> button;
                        if (button == 0) {
                            goto menu;
                        }
                        goto search;
                    }
                }
                else if (submenuNumber == 2) {
                    q = 0;
                    cout << "Напишите дату для поиска:>>";
                datesearch: cin >> dateSearch;
                    cout << "Результаты поиска:" << endl;
                    string line;
                    ifstream ReadFile("sales.txt");
                    while (getline(ReadFile, line)) {
                        if (line.find(dateSearch) != string::npos) {
                            q++;
                            cout << line << endl;
                        }
                    }
                    ReadFile.close();
                    // Переход к главному меню
                    if (q != 0) {
                        cout << endl << "0 - К главному меню" << endl;
                        cin >> button;
                        if (button == 0) {
                            goto menu;
                        }
                    }
                    if (q == 0) {
                        cout << "Не удалось найти товар с такой датой..." << endl;
                        cout << "Попробуйте ввести заново:>>";
                        goto datesearch;
                    }
                }
            }
            else if (menuNumber == 3) {
                string line;
                ifstream ReadFile("sold.txt");
                while (getline(ReadFile, line)) {
                    cout << line << endl;
                }
                ReadFile.close();
                cout << "0 - Назад" << endl;
                cin >> button;
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 4) {
                string sales;
                ifstream ReadFile("sales.txt");
                while (getline(ReadFile, sales)) {
                    cout << sales << endl;
                }
                ReadFile.close();
                cout << "Пожалуйста напишите номер материала, который вы бы хотели продать:>>";
                string elementToMove;
                cin >> elementToMove;
                // Перемещение материала из sales.txt в sold.txt
                string lineSell;
                string lineSold;
                bool elementFound = false;
                ifstream sale("sales.txt");
                ofstream saletemp("saletemp.txt");
                ifstream sold("sold.txt");
                ofstream soldtemp("soldtemp.txt");
                while (getline(sold, lineSold)) {
                    soldtemp << lineSold << endl;
                }
                while (getline(sale, lineSell)) {
                    if (lineSell.find(elementToMove) != string::npos) {
                        elementFound = true;
                        soldtemp << lineSell << endl;
                    }
                    else {
                        saletemp << lineSell << endl;
                    }
                }
                sale.close();
                saletemp.close();
                sold.close();
                soldtemp.close();
                remove("sales.txt");
                rename("saletemp.txt", "sales.txt");
                remove("sold.txt");
                rename("soldtemp.txt", "sold.txt");
                if (elementFound) {
                    cout << "Ваш запрос принят." << endl;
                }
                else {
                    cout << "Запас данного материала закончился, пожалуйста сделайте заказ на поставку!" << endl;
                }
                cout << "0 - К главному меню" << endl;
                cin >> button;
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 5) {
                string output;
                ifstream ReadFilenomaterials("nomaterials.txt");
                while (getline(ReadFilenomaterials, output)) {
                    cout << output << endl;
                }
                ReadFilenomaterials.close();
                cout << "Введите название и количество товара:>>";
                string noMaterial;
                cin >> noMaterial;
                int NumberOfNoMaterial;
                cin >> NumberOfNoMaterial;

                string noMat;
                string needMat;
                ifstream ReadFilenoMat("nomaterials.txt");
                ofstream ReadFilenoMattemp("nomaterialtemp.txt");
                ifstream file("need_materials.txt");
                ofstream filetemp("need_materialstemp.txt");
                while (getline(file, needMat)) {
                    filetemp << needMat << endl;
                }
                while (getline(ReadFilenoMat, noMat)) {
                    if (noMat.find(noMaterial) != string::npos) {
                        filetemp << noMat << endl;
                    }
                    else {
                        ReadFilenoMattemp << noMat << endl;
                    }
                }
                ReadFilenoMat.close();
                ReadFilenoMattemp.close();
                file.close();
                filetemp.close();
                remove("nomaterials.txt");
                rename("nomaterialtemp.txt", "nomaterials.txt");
                remove("need_materials");
                rename("need_materialstemp.txt", "need_materials.txt");
                cout << "Ваш запрос принят." << endl;
                cout << "0 - К главному меню" << endl;
                cin >> button;
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 6) {
                string sold;
                ifstream ReadFile("sold.txt");
                while (getline(ReadFile, sold)) {
                    cout << sold << endl;
                }
                ReadFile.close();
                string DeleteOrder;
                cout << "Напишите номер заказа который вы бы хотели удалить?>>";
                cin >> DeleteOrder;
                string LineDel;
                ifstream ReadFiledelOrder("sold.txt");
                ofstream DeleteOrdertemp("deltempsold.txt");
                while (getline(ReadFiledelOrder, LineDel)) {
                    if (LineDel.find(DeleteOrder) != string::npos) {
                        continue;
                    }
                    else {
                        DeleteOrdertemp << LineDel << endl;
                    }
                }
                ReadFiledelOrder.close();
                DeleteOrdertemp.close();
                remove("sold.txt");
                rename("deltempsold.txt", "sold.txt");
                cout << "Ваш запрос принят." << endl;
                cout << "0 - К главному меню" << endl;
                cin >> button;
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 7) {
                cout << "Программа завершена, мы будем рады вашему возвращению!";
                return 0;
            }
            else if (menuNumber == 8) {
                string instructions;
                ifstream ReadFile("instructions.txt");
                while (getline(ReadFile, instructions)) {
                    cout << instructions << endl;
                }
                ReadFile.close();
            }
            else {
                cout << "Enter numbers from 1 to 8.";
                goto menu;
            }
        }
        //Меню для аккаунта доставщика
        else if (username == "deliveryman" and password == "delivery123") {
            cout << "Приветствую, дорогой Доставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:";
        }
        //Меню для аккаунта поставщика
        else if (username == "provider" and password == "provider123") {
            cout << "Приветствую, дорогой Поставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:";
        }
        // В случае, если пароль или логин введены неверно
        else {
            cout << "Неверный пароль или логин." << endl << "Попробуйте ввести заново:>>" << endl;
            goto sign;
        }
    }
    // Если введен неправильный тип аккаунта
    else {
        cout << "Извините, но мы не нашли такой тип аккаунта, пожалуйста повторите." << endl;
        goto  start;
    }
    return 0;
}
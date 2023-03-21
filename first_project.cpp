#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct sold {
    string name;
    int quantity;
    string date;
};

int main() {
    string Deliveryman[] = {
        "1.Показать список материалов для доставки",
        "2.Показать доставленные заказы",
        "3.Доставить заказ",
        "4.Показать количество доставленных оборудований",
        "5.Показать количество заказанных товаров",
        "6.Показать мой заработок",
        "7.Выход",
        "8.Инструкции"
    };
    string Provider[] = {
        "1.Показать список товаров для поставки",
        "2.Показать количество поставляемого материала",
        "3.Показать материал с самым большим количеством заказов для доставки",
        "4.Показать материал с самым меньшим количеством заказов для доставки",
        "5.Выход",
        "6.Инструкции"
    };
    string username, password, nameSearch, dateSearch;
    int accountType, menuNumber, subMenuNumber, button;
start: cout << "Для запуска программы, пожалуйста введите тип аккаунта:>>";
    cout << endl << "1. Delivery man" << endl << "2. Salesman" << endl << "3. Provider" << endl;
    //Вводится тип аккаунта
    while (!(cin >> accountType) || accountType < 1 || accountType > 3) {
        cin.clear(); // clear the error flags
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // ignore the rest of the input
        cout << "Произошла ошибка. Введите число от 1 до 3" << endl;
    }
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
        if (username == "s" and password == "s123" and accountType == 2) {
            cout << "Приветствую, дорогой Продавец!" << endl;
            cout << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
        menu: cout << "1.Показать весь список материалов для продажи" << endl;
            cout << "2.Искать материал" << endl;
            cout << "3.Показать отчет по продаже" << endl << "4.Выполнить продажу оборудований" << endl;
            cout << "5.Сделать заказ отсутствующего товара" << endl << "6.Удалить заказ" << endl << "7.Выход" << endl;
            cout << "8.Промышленное производство" << endl;
            cout << "Выбор меню:>>";
            while (!(cin >> menuNumber) || menuNumber < 1 || menuNumber > 8) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число от 1 до 8" << endl;
                goto menu;
            }
            if (menuNumber == 1) {
                string sales;
                ifstream ReadFile("sales.txt");
                if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                    cout << "Нет товаров для продажи." << endl;
                }
                else {
                    while (getline(ReadFile, sales)) {
                        cout << sales << endl;
                    }
                }
                ReadFile.close();

                cout << "0 - К главному меню" << endl;
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 2) {
                cout << "Выберите: каким способом хотите искать:" << endl << "1.По названию" << endl << "2.По дате" << endl;
                while (!(cin >> subMenuNumber) || subMenuNumber > 2 or subMenuNumber < 1) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 1 или 2, чтобы выбрать метод поиска." << endl;
                }
                int q = 0;
                if (subMenuNumber == 1) {
                    cout << "Напишите название материала для поиска:>>";
                search: cin >> nameSearch;
                    cout << "Результаты поиска:" << endl;
                    ifstream ReadFile("sales.txt");
                    if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                        cout << "Нет товаров для продажи." << endl;
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
                        if (q != 0) {
                            cout << endl << "0 - К главному меню" << endl;
                            while (!(cin >> button) || button != 0) {
                                cin.clear(); // clear the error flags
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                            }
                            if (button == 0) {
                                goto menu;
                            }
                        }
                        else if (q == 0) {
                            cout << "Не удалось найти товар с таким названием..." << endl;
                            cout << "Попробуйте ввести заново:>>";
                            goto search;
                        }
                    }
                    cout << endl << "0 - К главному меню" << endl;
                    while (!(cin >> button) || button != 0) {
                        cin.clear(); // clear the error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                        cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                    }
                    if (button == 0) {
                        goto menu;
                    }
                    ReadFile.close();
                }
                else if (subMenuNumber == 2) {
                    q = 0;
                    cout << "Напишите дату для поиска:>>";
                datesearch: cin >> dateSearch;
                    cout << "Результаты поиска:" << endl;
                    string line;
                    ifstream ReadFile("sales.txt");
                    if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                        cout << "Нет товаров для продажи." << endl;
                    }
                    else {
                        while (getline(ReadFile, line)) {
                            if (line.find(dateSearch) != string::npos) {
                                q++;
                                cout << line << endl;
                            }
                        }

                        // Переход к главному меню
                        if (q != 0) {
                            cout << endl << "0 - К главному меню" << endl;
                            while (!(cin >> button) || button != 0) {
                                cin.clear(); // clear the error flags
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                            }
                            if (button == 0) {
                                goto menu;
                            }
                        }
                        else if (q == 0) {
                            cout << "Не удалось найти товар с такой датой..." << endl;
                            cout << "Попробуйте ввести заново:>>";
                            goto datesearch;
                        }
                    }
                    cout << endl << "0 - К главному меню" << endl;
                    while (!(cin >> button) || button != 0) {
                        cin.clear(); // clear the error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                        cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                    }
                    if (button == 0) {
                        goto menu;
                    }
                    ReadFile.close();
                }
            }
            else if (menuNumber == 3) {
                string line;
                ifstream ReadFile("sold.txt");
                if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                    cout << "Нет проданных товаров." << endl;
                }
                else {
                    while (getline(ReadFile, line)) {
                        cout << line << endl;
                    }
                }
                ReadFile.close();
                cout << endl << "0 - Назад" << endl;
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 4) {
                string sales;
                ifstream ReadFile("sales.txt");
                if (ReadFile.peek() == std::ifstream::traits_type::eof()) {
                    cout << "Нет товаров для продажи." << endl;
                }
                else {
                    while (getline(ReadFile, sales)) {
                        cout << sales << endl;
                    }
                    cout << "Пожалуйста напишите название материала, который вы бы хотели продать:>>";
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
                }
                ReadFile.close();
                cout << endl << "0 - К главному меню" << endl;
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 5) {
                string output;
                ifstream ReadFilenomaterials("nomaterials.txt");
                // Check if the file is empty
                if (ReadFilenomaterials.peek() == ifstream::traits_type::eof()) {
                    cout << "Нет отсутсвующих товаров." << endl;
                }
                else {
                    while (getline(ReadFilenomaterials, output)) {
                        cout << output << endl;
                    }
                    cout << "Введите название и количество товара:>>";
                    string noMaterial;
                    cin >> noMaterial;
                    int NumberOfNoMaterial;
                    while (!(cin >> NumberOfNoMaterial)) {
                        cin.clear(); // clear the error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                        cout << "Произошла ошибка. Введите число, сколько вы бы хотели заказать." << endl;
                    }

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
                            filetemp << noMat << " " << NumberOfNoMaterial << endl;
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
                    cout << endl << "0 - К главному меню" << endl;
                }
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
                ReadFilenomaterials.close();

            }
            else if (menuNumber == 6) {
                string sold;
                ifstream ReadFile("sold.txt");
                if (ReadFile.peek() == ifstream::traits_type::eof()) {
                    cout << "Нет проданных товаров." << endl;
                }
                else {
                    while (getline(ReadFile, sold)) {
                        cout << sold << endl;
                    }
                    string DeleteOrder;
                    cout << "Напишите название товара заказа который вы бы хотели удалить?>>";
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
                }
                ReadFile.close();
                cout << endl << "0 - К главному меню" << endl;
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
            }
            else if (menuNumber == 7) {
                cout << "Программа завершена, мы будем рады вашему возвращению!";
                return 0;
            }
            else if (menuNumber == 8) {
                cout << "Инструкция:" << endl;
                string instructions;
                ifstream ReadFile("instructions.txt");
                while (getline(ReadFile, instructions)) {
                    cout << instructions << endl;
                }
                ReadFile.close();
                cout << endl << "0 - К главному меню" << endl;
                while (!(cin >> button) || button != 0) {
                    cin.clear(); // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                    cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                }
                if (button == 0) {
                    goto menu;
                }
            }
            else {
                cout << "Enter numbers from 1 to 8.";
                goto menu;
            }
        }

        //Меню для аккаунта доставщика
        else if (username == "d" and password == "d123" and accountType == 1) {
            cout << "Приветствую, дорогой Доставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
        menu2: for (auto now : Deliveryman) {
            cout << now << endl;
        }
        cout << "Выбор меню:>>";
        while (!(cin >> menuNumber) || menuNumber < 1 || menuNumber > 8) {
            cin.clear(); // clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Произошла ошибка. Введите число от 1 до 8" << endl;
            goto menu2;
        }
        if (menuNumber == 1) {
            string line;
            ifstream ReadFile("sold.txt");
            if (ReadFile.peek() == ifstream::traits_type::eof()) {
                cout << "Нет проданных товаров." << endl;
            }
            else {
                while (getline(ReadFile, line)) {
                    cout << line << endl;
                }
            }
            ReadFile.close();
            cout << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 2) {
            string line;
            ifstream ReadFile("delivered.txt");
            if (ReadFile.peek() == ifstream::traits_type::eof()) {
                cout << "Нет доставленнных товаров." << endl;
            }
            else {
                while (getline(ReadFile, line)) {
                    cout << line << endl;
                }
            }
            ReadFile.close();
            cout << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 3) {
            string line;
            ifstream ReadFile("sold.txt");
            if (ReadFile.peek() == ifstream::traits_type::eof()) {
                cout << "Нет проданных товаров." << endl;
            }
            else {
                while (getline(ReadFile, line)) {
                    cout << line << endl;
                }
                cout << "Какой заказ был доставлен? Введите название оборудования:>>";
                string ordered;
                cin >> ordered;
                string delivered;
                string sold;
                ifstream ReadSold("sold.txt");
                ofstream WriteSoldTemp("soldtemp");
                ifstream ReadDelivered("delivered.txt");
                ofstream WriteDeliveredTemp("deliveredtemp");
                while (getline(ReadDelivered, delivered)) {
                    WriteDeliveredTemp << delivered << endl;
                }
                while (getline(ReadSold, sold)) {
                    if (sold.find(ordered) != string::npos) {
                        WriteDeliveredTemp << sold << endl;
                    }
                    else {
                        WriteSoldTemp << sold << endl;
                    }
                }
                ReadSold.close();
                ReadDelivered.close();
                WriteDeliveredTemp.close();
                WriteSoldTemp.close();
                remove("sold.txt");
                remove("delivered.txt");
                rename("soldtemp", "sold.txt");
                rename("deliveredtemp", "delivered.txt");
                cout << "Ваш запрос принят." << endl;
            }
            ReadFile.close();
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 4) {
            int count = 0;
            string line;
            ifstream ReadDelivered("delivered.txt");
            if (ReadDelivered.peek() == ifstream::traits_type::eof()) {
                cout << "Нет доставленных товаров." << endl;
            }
            else {
                while (getline(ReadDelivered, line)) {
                    count++;
                }
                cout << "Количество доставленных товаров: ";
                cout << count;
            }
            ReadDelivered.close();

            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 5) {
            int count = 0;
            string line;
            ifstream ReadDelivered("sold.txt");
            if (ReadDelivered.peek() == ifstream::traits_type::eof()) {
                cout << "Нет проданных товаров." << endl;
            }
            else {
                while (getline(ReadDelivered, line)) {
                    count++;
                }
                cout << "Количество заказанных товаров: ";
                cout << count;
            }
            ReadDelivered.close();
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 6) {
            int stake = 1000;
            string line;
            ifstream ReadFile("delivered.txt");
            if (ReadFile.peek() == ifstream::traits_type::eof()) {
                cout << "Нет доставленных товаров." << endl;
            }
            else {
                while (getline(ReadFile, line)) {
                    cout << line << "- " << stake << "с" << endl;
                }
                int count = 0;
                string lineCount;
                ifstream ReadDelivered("delivered.txt");
                while (getline(ReadDelivered, lineCount)) {
                    count++;
                }
                cout << "Ваш заработок: " << count * stake << "сомов";
                ReadDelivered.close();
            }
            ReadFile.close();
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        else if (menuNumber == 7) {
            cout << "Программа завершена, мы будем рады вашему возвращению!";
            return 0;
        }
        else if (menuNumber == 8) {
            cout << "Инструкция:" << endl;
            string instructions;
            ifstream ReadFile("instructions.txt");
            while (getline(ReadFile, instructions)) {
                cout << instructions << endl;
            }
            ReadFile.close();
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu2;
            }
        }
        }

        //Меню для аккаунта поставщика
        else if (username == "p" and password == "p123" and accountType == 3) {
            cout << "Приветствую, дорогой Поставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 5:" << endl;
        menu3: for (auto now : Provider) {
            cout << now << endl;
        }
        cout << "Выбор меню:>>";
        while (!(cin >> menuNumber) || menuNumber < 1 || menuNumber > 6) {
            cin.clear(); // clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Произошла ошибка. Введите число от 1 до 6" << endl;
            goto menu3;
        }
        if (menuNumber == 1) {
            string need;
            ifstream ReadNeed("need_materials.txt");
            if (ReadNeed.peek() == ifstream::traits_type::eof()) {
                cout << "Нет товаров для поставки." << endl;
            }
            else {
                while (getline(ReadNeed, need)) {
                    cout << need << endl;
                }
            }
            cout << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu3;
            }
        }
        else if (menuNumber == 2) {
            ifstream ReadNeed("need_materials.txt");
            if (ReadNeed.peek() == ifstream::traits_type::eof()) {
                cout << "Нет товаров для поставки." << endl;
            }
            else {
                int count = 0;
                string lineNeed;
                while (getline(ReadNeed, lineNeed)) {
                    count++;
                }
                cout << "Количество поставляемого товара: ";
                cout << count;
            }
            ReadNeed.close();
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu3;
            }
        }
        else if (menuNumber == 3 or menuNumber == 4) {
            ifstream ReadSold("sold.txt");
            if (ReadSold.peek() == ifstream::traits_type::eof()) {
                cout << "Нет заказов." << endl;
            }
            else {
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
                    cout << "0 - К главному меню" << endl;
                    while (!(cin >> button) || button != 0) {
                        cin.clear(); // clear the error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                        cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
                    }
                    if (button == 0) {
                        goto menu3;
                    }
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
            cout << endl << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu3;
            }
        }
        else if (menuNumber == 5) {
            cout << "Программа завершена, мы будем рады вашему возвращению!";
            return 0;
        }
        else if (menuNumber == 6) {
            cout << "Инструкция:" << endl;
            string instructions;
            ifstream ReadFile("instructions.txt");
            while (getline(ReadFile, instructions)) {
                cout << instructions << endl;
            }
            ReadFile.close();
            cout << "0 - К главному меню" << endl;
            while (!(cin >> button) || button != 0) {
                cin.clear(); // clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
                cout << "Произошла ошибка. Введите число 0, чтобы выйти в главное меню." << endl;
            }
            if (button == 0) {
                goto menu3;
            }
        }
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
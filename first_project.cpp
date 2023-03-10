#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string username, password;
    int accounttype;
    start : cout << "Для запуска программы, пожалуйста введите тип аккаунта:>>";
    cout << endl << "1. Delivery man" << endl << "2. Salesman" << endl << "3. Provider" << endl;
    //Вводится тип аккаунта
    cin >> accounttype;
    if(accounttype == 1 or accounttype == 2 or accounttype == 3){
        if(accounttype == 1){
            cout << "Вы выбрали тип аккаунта: доставщик." << endl;
        }
        else if(accounttype == 2){
            cout << "Вы выбрали тип аккаунта: продавец." << endl;
        }
        else if(accounttype == 3){
            cout << "Вы выбрали тип аккаунта: поставщик." << endl;
        }
        //Вводится логин и пароль для авторизации
        cout << "Пожалуйста, введите ваш логин и пароль:>>" << endl;
        cout << "Логин:>>";
        cin >> username;
        cout << "Пароль:>>";
        cin >> password;
        //Меню для аккаунта продавца
        if(username == "salesman" and password == "salesman123"){
            cout <<"Приветствую, дорогой Продавец!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:" << endl;
        }
        //Меню для аккаунта доставщика
        else if(username == "deliveryman" and password == "delivery123"){
            cout << "Приветствую, дорогой Доставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:";
        }
        //Меню для аккаунта поставщика
        else if(username == "provider" and password == "provider123"){
            cout << "Приветствую, дорогой Поставщик!" << endl << "Пожалуйста наберите номер меню для работы с программой, если закончили, то наберите 7:";
        }
    }
    else{
        cout << "Извините, но мы не нашли такой тип аккаунта, пожалуйста повторите." << endl;
        goto  start;
    }
    return 0;
}




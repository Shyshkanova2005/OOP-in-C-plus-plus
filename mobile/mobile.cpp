//1. Задание: Система управления ремонтом мобильных телефонов
//Цель :
//Разработать консольную программу на C++, которая имитирует систему управления ремонтом мобильных телефонов.Пользователь может регистрировать телефон на ремонт, обновлять статус ремонта и проверять текущий статус ремонта.
//
//Программа должна предлагать пользователю следующие действия :
//
//Регистрация телефона на ремонт.
//Обновление статуса ремонта.
//Просмотр информации о телефоне и его ремонтном статусе.
//Выход.

#include <iostream>
#include <string>
using namespace std;

struct Status {
    string registered;
    string in_process;
    string completed;
};

struct Infophone {
    string owner;
    string phonemodel;
    string status;
   
};


class Mobile {
private:
    Infophone information;
    Status phonestatus;

public:
    Mobile(Infophone newInformation, Status newStatus) {
        information = newInformation;
        phonestatus = newStatus;
    }

    void displayInfo() {
        cout << "Name owner:" << information.owner << "\n";
        cout << "Model Phone:" << information.phonemodel << "\n";
        cout << "Status:" <<information.status  << "\n";
    }
    string getStatus() {
        return information.status;
   }
    void setStatus(string update) {
        information.status = update;
    }
    void updateStatus() {
        cout << "New Status:" << information.status << endl;
    }
    void checkStatus(string phonemodel) {
        if (information.phonemodel != information.status) {
            cout << "Status of " <<information.phonemodel << " owned by " << information.owner << " is: " << getStatus() << endl;
        }
        else {
            cout << "Phone not found." << endl;
        }
        
    }


};



int main()

{
    Infophone newPhone = {"Sam", "Samsung s23", "Registered" };
    Status newStatus = { "Registered", "In_Process", "Completed" };
    Mobile myMobile = { newPhone, newStatus };
    myMobile.displayInfo();
    myMobile.setStatus("in_process");
    myMobile.updateStatus();
    myMobile.checkStatus("Samsung s23");
    return 0;
}


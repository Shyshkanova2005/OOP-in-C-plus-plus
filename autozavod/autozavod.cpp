#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Car {
public:
    int wheels;
    string color;

    Car(string c, int w) {
        color = c;
        wheels = w;
    }

    virtual void displayInfo() const {
        cout << "Цвет: " << color << endl << "Колличество шин: " << wheels << endl;
    }

    virtual ~Car() {}

};

class Sedan : public Car {
public:
    int velocity;

    Sedan(string c, int w, int v) : Car(c, w), velocity(v) {
        if (w != 4) {
            throw invalid_argument("Легковые автомобили должны иметь 4 колеса.");
        }
    }

    virtual  void displayInfo() const override {
        Car::displayInfo();
        cout << "Скорость: " << velocity << endl;
    }
    
};

class Pickup : public Car {
public:
    int liftingCapacity;
  
    Pickup(string c, int w, int lc) : Car(c, w), liftingCapacity(lc){
        if (w != 4) {
            throw invalid_argument("Пикап должнен иметь 4 колеса.");
        }
    }

    virtual  void displayInfo() const override {
        Car::displayInfo();
        cout << "Грузоподъемность: " << liftingCapacity << endl;
    }

};

class Truck : public Car {
public:
    int amountAxis;

    Truck(string c, int w, int aa) : Car(c, w), amountAxis(aa) {
        if (w != 4) {
            throw invalid_argument("Грузовик должен иметь 4 колеса.");
        }
    }

    virtual  void displayInfo() const override {
        Car::displayInfo();
        cout << "Количество осей: " << amountAxis << endl;
    }
};

class Bus : public Car {
public:
    int amountPlaces;

    Bus(string c, int w, int ap) : Car(c, w), amountPlaces(ap) {
        if (w != 4) {
            throw invalid_argument("Автобус должен иметь 4 колеса.");
        }
    }

    virtual void displayInfo() const override {
        Car::displayInfo();
        cout << "Количество мест: " << amountPlaces << endl;
    }
};

Car* carInfo(string type, string color, int wheels, int uniqueParameter) {

            if (type == "Sedan") {
                return new Sedan(color, wheels, uniqueParameter);
            }
            else if (type == "Pickup") {
                return new  Pickup(color, wheels, uniqueParameter);
            }
            else if (type == "Truck") {
                return new Truck(color, wheels, uniqueParameter);
            }
            else if (type == "Bus") {
                return new Bus(color, wheels, uniqueParameter);
            }

    }
int main()
{
    setlocale(LC_ALL, "Russian");

    int numCar;
    cout << "Введите количество автомобилей: ";
    cin >> numCar;

    for (int i = 0; i < numCar; ++i) {
        string type;
        string color;
        int wheels;
        int uniqueParameter;

        cout << "Введите тип автомобиля (Sedan, Pickup, Truck, Bus): ";
        cin >> type;
        cout << "Введите цвет автомобиля: ";
        cin >> color;
        cout << "Введите количество колёс: ";
        cin >> wheels;
        cout << "Введите уникальный параметр (максимальная скорость для Sedan, грузоподъемность для Pickup, количество осей для Truck, количество мест для Bus): ";
        cin >> uniqueParameter;

        try {
           
            Car* myCar = carInfo(type, color, wheels, uniqueParameter);
            myCar->displayInfo();
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid argument error: " << e.what() << endl;

        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    return 0;
}



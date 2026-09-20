#include <iostream>
using namespace std;

class Time{
    int hour;
    int min;
    int sec;
public:
    void print(){cout << "Time: " <<  hour << ":" << min << ":" << sec << endl;}
    void uptime();
    int getHour() {return hour;}
    void setHour(int h);
    int getMinute() {return min;}
    void setMinute(int m);
    int getSecond() {return sec;}   
    void setSecond(int s);
    void setTime(int h, int m, int s);
};

int main()
{
    Time time;

    // проверка перехода секунд 
    time.setTime(10, 15, 59);
    time.print();
    time.uptime();
    cout << "+1 сек" << endl;
    time.print();

    // проверка  минут 
    time.setTime(10, 59, 59);
    time.print();
    time.uptime();
    cout << "+1 сек" << endl;
    time.print();

    // проверка часов
    time.setTime(23, 59, 59);
    time.print();
    time.uptime();
    cout << "+1 сек" << endl;
    time.print();

    time.setHour(10);
    time.setMinute(30);
    time.setSecond(45);
    time.print();

    // обработка ввода
    time.setHour(25);
    time.setMinute(70);
    time.setSecond(-5);

    return 0;
}


// Реализации ф-й


void Time::uptime(){
    if (sec == 59){
        sec = 0;
        min++;
        if (min == 60){
            min=0;
            hour++;
            if(hour ==24){
                hour = 0;
            }
        }
    } else{
        sec++;
    }
}

void Time::setHour(int h) {
    if (h >= 0 && h < 24) {
        hour = h;
    } else {
        std::cout << "Ошибка: неверное значение часов: " << h << endl;
    }
}

void Time::setMinute(int m) {
    if (m >= 0 && m < 60) {
        min = m;
    } else {
        std::cout << "Ошибка: неверное значение минут: " << m << endl;
    }
}


void Time::setSecond(int s){
    if (s >= 0 && s < 60) {
        sec = s;
    } else {
        std::cout << "Ошибка: неверное значение секунд: " << s << endl;
    }
}


void Time::setTime(int h, int m, int s){
    if (h >= 0 && h < 24) {
        hour = h;
    } else {
        std::cout << "Ошибка: неверное значение часов: " << h << endl;
    }

    if (m >= 0 && m < 60) {
        min = m;
    } else {
        std::cout << "Ошибка: неверное значение минут: " << m << endl;
    }

    if (s >= 0 && s < 60) {
        sec = s;
    } else {
        std::cout << "Ошибка: неверное значение секунд: " << s << endl;
    }
}




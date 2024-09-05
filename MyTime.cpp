#include "MyTime.h"
#include <iostream>


MyTime::MyTime()          // конструктор по умолчанию
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}
 
MyTime::MyTime(int h, int m, int s)           // конструктор с параметрами hours, minutes, seconds
{
	if ((h >= 0) && (m >= 0) && (s >= 0) && (m < 60) && (s < 60)) {   // если аргументы корректны
		hours = h;
		minutes = m;
		seconds = s;
	}
	else {                                                            // иначе пересчитает и запишет корректно
		int time = h * 3600 + m * 60 + s;
		hours = time / 3600;
		minutes = (time - hours * 3600) / 60;
		seconds = (time - hours * 3600) % 60;
	}
}

MyTime::MyTime(int s)                           // конструктор с параметрами seconds
{
	hours = s / 3600;
	minutes = (s - hours * 3600) / 60;
	seconds = (s - hours * 3600) % 60;
}

MyTime::MyTime(int m, int s)                    // конструктор с параметрами minutes и seconds
{
	int time = m * 60 + s;
	hours = time / 3600;
	minutes = (time - hours * 3600) / 60;
	seconds = (time - hours * 3600) % 60;
}


MyTime::MyTime(MyTime& Time_copy)           // конструктор копий
{
	hours = Time_copy.hours;
	minutes = Time_copy.minutes;
	seconds = Time_copy.seconds;
}

MyTime::~MyTime() = default;              // деструктор

void MyTime::print() const                            // вывод
{
	if (((*this).seconds < 0) || ((*this).minutes < 0) || ((*this).hours < 0)) std::cout << "- ";                  // если время отрицательное, в начале ставим -
	std::cout << abs((*this).hours) << " : " << abs((*this).minutes) << " : " << abs((*this).seconds);
}


MyTime& MyTime::operator=(const MyTime &t2)                              // оператор присваивания
{
	hours = t2.hours;
	minutes = t2.minutes;
	seconds = t2.seconds;
	return(*this);
}

MyTime MyTime::operator+(int value)   // оператор сложения ТД и int
{
	int time = hours * 3600 + minutes * 60 + seconds + value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
} 

MyTime MyTime::operator+(const MyTime &t2)   // оператор сложения ТД и ТД
{
	int time = (hours + t2.hours) * 3600 + (minutes + t2.minutes) * 60 + seconds + t2.seconds;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime operator+(int value, MyTime& t2)   // оператор сложения int и ТД (дружественная функция)
{
	int time = t2.hours * 3600 +  t2.minutes * 60  + t2.seconds + value;
	MyTime sum;
	sum.hours = time / 3600;
	sum.minutes = (time - sum.hours * 3600) / 60;
	sum.seconds = (time - sum.hours * 3600) % 60;
	return(sum);
}

MyTime MyTime::operator-(int value)                //DT - int
{
	int time = hours * 3600 + minutes * 60 + seconds - value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime MyTime::operator-(const MyTime& t2)              //DT - DT
{
	int time = (hours - t2.hours) * 3600 + (minutes - t2.minutes) * 60 + seconds - t2.seconds;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime operator-(int value, MyTime& t2)                //int - DT (дружественная функция)
{
	int time = value - t2.hours * 3600 - t2.minutes * 60 - t2.seconds;
	MyTime diff;
	diff.hours = time / 3600;
	diff.minutes = (time - diff.hours * 3600) / 60;
	diff.seconds = (time - diff.hours * 3600) % 60;
	return(diff);
}

MyTime MyTime::operator*(int value)                    //DT * int
{
	int time = (hours * 3600 + minutes * 60 + seconds) * value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime operator*(int value, MyTime& t2)   // int * DT (дружественная функция)
{
	int time = (t2.hours * 3600 + t2.minutes * 60 + t2.seconds) * value;
	MyTime sum;
	sum.hours = time / 3600;
	sum.minutes = (time - sum.hours * 3600) / 60;
	sum.seconds = (time - sum.hours * 3600) % 60;
	return(sum);
}

MyTime MyTime::operator/(int value)       //DT / int
{
	int time = (hours * 3600 + minutes * 60 + seconds) / value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime MyTime::operator+=(int value)                    // накопление +=
{
	int time = hours * 3600 + minutes * 60 + seconds + value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime MyTime::operator-=(int value)                    // накопление -=
{
	int time = hours * 3600 + minutes * 60 + seconds - value;
	(*this).hours = time / 3600;
	(*this).minutes = (time - hours * 3600) / 60;
	(*this).seconds = (time - hours * 3600) % 60;
	return(*this);
}

MyTime& MyTime::operator++()                     // префиксный инкремент
{
	if (((*this).seconds < 0) || ((*this).minutes < 0) || ((*this).hours < 0)) {     // если время отрицательное
		int time = hours * 3600 + minutes * 60 + seconds + 1;
		(*this).hours = time / 3600;
		(*this).minutes = (time - hours * 3600) / 60;
		(*this).seconds = (time - hours * 3600) % 60;
		return(*this);
	}
	else
	{
		(*this).seconds++;
		if ((*this).seconds == 60) {
			(*this).minutes++;
			(*this).seconds = 0;
		}
			if ((*this).minutes == 60){
				(*this).hours++;
				(*this).minutes = 0;
		}
	}
	return(*this);
}

MyTime MyTime::operator++(int)                  // постфиксный инкремент
{
	MyTime temp = (*this);
	if (((*this).seconds < 0) || ((*this).minutes < 0) || ((*this).hours < 0)) {     // если время отрицательное
		int time = hours * 3600 + minutes * 60 + seconds + 1;
		(*this).hours = time / 3600;
		(*this).minutes = (time - hours * 3600) / 60;
		(*this).seconds = (time - hours * 3600) % 60;
		return(*this);
	}
	else
	{
		(*this).seconds++;
		if ((*this).seconds == 60) {
			(*this).minutes++;
			(*this).seconds = 0;
		}
		if ((*this).minutes == 60) {
			(*this).hours++;
			(*this).minutes = 0;
		}
	}
	return(temp);
}

MyTime& MyTime::operator--()                // префиксный декремент
{
	if (((*this).seconds < 0) || ((*this).minutes < 0) || ((*this).hours < 0)) {     // если время отрицательное
		(*this).seconds--;
		if ((*this).seconds == -60) {
			(*this).minutes--;
			(*this).seconds = 0;
		}
		if ((*this).minutes == -60) {
			(*this).hours--;
			(*this).minutes = 0;
		}
		}
	else
	{
		int time = hours * 3600 + minutes * 60 + seconds - 1;
		(*this).hours = time / 3600;
		(*this).minutes = (time - hours * 3600) / 60;
		(*this).seconds = (time - hours * 3600) % 60;
		return(*this);
	}
	return(*this);
}

MyTime MyTime::operator--(int)                // постфиксный декремент
{
	MyTime temp = *this;
	if (((*this).seconds < 0) || ((*this).minutes < 0) || ((*this).hours < 0)) {     // если время отрицательное
		(*this).seconds--;
		if ((*this).seconds == -60) {
			(*this).minutes--;
			(*this).seconds = 0;
		}
		if ((*this).minutes == -60) {
			(*this).hours--;
			(*this).minutes = 0;
		}
	}
	else
	{
		int time = hours * 3600 + minutes * 60 + seconds - 1;
		(*this).hours = time / 3600;
		(*this).minutes = (time - hours * 3600) / 60;
		(*this).seconds = (time - hours * 3600) % 60;
		return(*this);
	}
	return(temp);
}



bool MyTime::operator<(const MyTime& t2) const                             // операторы сравнения 
{
	if (hours < t2.hours) return true; else 
		if (hours > t2.hours) return false; else
			if (minutes < t2.minutes) return true; else 
					if (minutes > t2.minutes) return false; else 
						if (seconds < t2.seconds) return true; else return false;
}


bool MyTime::operator>(const MyTime& t2) const
{
	if (hours > t2.hours) return true; else
		if (hours < t2.hours) return false; else
			if (minutes > t2.minutes) return true; else
				if (minutes < t2.minutes) return false; else
					if (seconds > t2.seconds) return true; else return false;
}

bool MyTime::operator<=(const MyTime& t2) const
{
	if (hours < t2.hours) return true; else
		if (hours > t2.hours) return false; else
			if (minutes < t2.minutes) return true; else
				if (minutes > t2.minutes) return false; else
					if (seconds <= t2.seconds) return true; else return false;
}

bool MyTime::operator>=(const MyTime& t2) const
{
	if (hours > t2.hours) return true; else
		if (hours < t2.hours) return false; else
			if (minutes > t2.minutes) return true; else
				if (minutes < t2.minutes) return false; else
					if (seconds >= t2.seconds) return true; else return false;
}

bool MyTime::operator==(const MyTime& t2) const
{
	if (hours != t2.hours) return false; else
		if (minutes != t2.minutes) return false; else
			if (seconds != t2.seconds) return false; else
				return true;
}

bool MyTime::operator!=(const MyTime& t2) const
{
	if ((hours == t2.hours) && (minutes == t2.minutes) && (seconds == t2.seconds))
		return false;
	else
		return true;
}

int MyTime::operator[] (int pos) const        // вывод 
{
	try {
		if ((pos != 1) && (pos != 2) && (pos != 3)) throw MyException("Wrong argument: '1'-hours, '2'-minutes, '3'-seconds ");
		if (pos == 1) return hours;
		if (pos == 2) return minutes;
		if (pos == 3) return seconds;
	}
	catch (const MyException& ex) {
		std::cout << ex.what() << '\n';
		return NULL;
	};

}

int MyTime::toInt()
{
	return (hours * 3600 + minutes * 60 + seconds);
}

/* 
                о   о 
  ____   _____ ______ _ 
 |  _ \ / ____|  ____| |
 | |_) | |    | |__  | |
 |  _ <| |    |  __| | |
 | |_) | |____| |____|_|
 |____/ \_____|______(_)
                        
                       */

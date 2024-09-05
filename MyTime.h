#ifndef MYTIME_H
#define MYTIME_H

#include <string>

class MyException : public std::exception
{
	std::string    m_msg;
public:
	explicit MyException(const char* msg) :m_msg(msg) {}
	[[nodiscard]] const char* what() const override { return m_msg.c_str(); }
};

class MyTime
{
private:
	int seconds;
	int minutes;
	int hours;

public:
	MyTime();                                            // конструктор по умолчанию
	MyTime(int h, int m, int s);                         // конструктор с параметрами
	MyTime(int s);                                       // конструктор с параметрами seconds
	MyTime(int m, int s);                                // конструктор с параметрами seconds и minutes
	MyTime(MyTime& Time_copy);                           // конструктор копий
	~MyTime();                                           // деструктор
	void print() const;                                  // вывод
	MyTime& operator=(const MyTime& t2);                 // оператор присваивания
	MyTime operator+(int value);                         // оператор сложения ТД и int
	MyTime operator+(const MyTime& t2);                  // оператор сложения ТД и ТД
	friend MyTime operator+(int value, MyTime& t2);      // оператор сложения int и ТД (дружественная функция)
	MyTime operator-(int value);                         // оператор вычитания ТД и int
	MyTime operator-(const MyTime& t2);                  // оператор вычитания ТД и ТД
	friend MyTime operator-(int value, MyTime& t2);      // оператор вычитания int и ТД (дружественная функция)
	MyTime operator*(int value);                         // оператор умножения ТД и int
	friend MyTime operator*(int value, MyTime& t2);      // оператор умножения int и ТД
	                                                     // оператор умножения ТД и ТД не имеет смысла
	MyTime operator/(int value);                         // оператор деления ТД и int
	                                                     // оператор деления ТД и ТД не имеет смысла
	                                                     // оператор деления int и ТД не имеет смысла
	MyTime operator+=(int value);                        // накопление +=
	MyTime operator-=(int value);                        // накопление -=
	MyTime& operator++();                                // префиксный инкремент
	MyTime operator++(int);                              // постфиксный инкремент
	MyTime& operator--();                                // префиксный декремент
	MyTime operator--(int);                              // постфиксный декремент

	bool operator<(const MyTime& t2) const;              // операторы сравнения 
	bool operator>(const MyTime& t2) const;
	bool operator<=(const MyTime& t2) const;
	bool operator>=(const MyTime& t2) const;

	bool operator==(const MyTime& t2) const;
	bool operator!=(const MyTime& t2) const;

	int operator[] (int pos) const;                     // взятие элемента по номеру

	int toInt();                                        // преобразование в int
};

#endif //MYTIME_H

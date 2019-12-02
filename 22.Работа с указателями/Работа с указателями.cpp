﻿// Работа с указателями.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
void swap(int*a, int*b) 
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int msort(int* one, int* two, int* three)
{
	if (*one > *two)
	{
		swap(one, two);
	}
		if (*two > *three)
		{
			swap(two, three);
		}
		else 
		{
			return *three;
		}
		  if (*one > *two)
		{
			swap(one, two);
		}
		return *three;
}
void Info(const int* value)
{
	cout << value << "  " << "Значение: " << *value << endl;
}
int* Add(int* first, const int* second) 
{
	*first = *first + *second;
	return first;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int a = -220, b = 7, c = 0;
	Info(&a);
	Info(&b);
	Info(&c);
	cout << "Максимум  " << msort(&a, &b, &c) << endl;
	Add(Add(&a, &b), &c);
	Info(&a);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

﻿// 18. Min и Max в одномерном массиве.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 100 - rand() % 201;
		cout << arr[i] << " ";
	}
	int max = arr[0], min = arr[0];
		for (int j = 1; j < 20; j++)
		{
			if (max > arr[j]) 
			{
				max = arr[j];
			}
			if (min < arr[j])
			{
				min = arr[j];
			}
			
		}
		cout << endl << max << endl << min << endl;
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

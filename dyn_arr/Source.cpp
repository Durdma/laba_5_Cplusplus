#define NOMINMAX
#define _CRTDBG_MAP_ALLOC

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

using namespace std;

//ВВод массива

float* f_input_arr(int& len, int& count)
{

	float numb = 0;
	bool check = true;
	float* arr_of_numbs = new float[len];

	cout << "Введите массив вещественных чисел: " << endl;

	

	//Цикл ввода массива

	do
	{

		if (count >= len)		//Выделение памяти для динамического массива
		{

			len = 2 * len;

			float* temp_arr = new float[len];

			for (int i = 0; i < count; i++)
			{

				temp_arr[i] = arr_of_numbs[i];

			}

			delete[] arr_of_numbs;

			arr_of_numbs = new float[len];

			for (int i = 0; i < count; i++)
			{

				arr_of_numbs[i] = temp_arr[i];

			}

			delete[] temp_arr;

		}

		cout << count << "й элемент: ";
		cin >> numb;
		cout << endl;

		while (!cin.good() || cin.peek() != '\n')		//Проверка корректности введнных данных
		{

			cerr << "Некорректный ввод данных!!!" << endl;
			cout << "Вводимый элемент должен быть числом. Дробная часть должна быть отделена точкой!!!" << endl;
			cout << "Повторите ввод!!!" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << count << "й элемент: ";
			cin >> numb;
			cout << endl;

		}

		arr_of_numbs[count] = numb;

		cout << "Продолжить ввод элементов? (1 - да / 0 - нет)" << endl;
		cin >> check;
		cout << endl;

		while (!cin.good() || cin.peek() != '\n')		//Проверка корректности введенного флага
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cerr << "Неккоректный ввод!!!" << endl;
			cout << "Введите 1 - для продолжения ввода элементов, либо 0 - для завершения ввода!!!" << endl;
			cin >> check;
			cout << endl;

		}

		count++;

	} while (check == true);		//Условие выхода из цикла ввода элементов

	if (count < len)				//Обрезание динамического массива
	{

		float* temp_arr = new float[count];

		for (int i = 0; i < count; i++)
		{

			temp_arr[i] = arr_of_numbs[i];

		}

		delete[] arr_of_numbs;

		arr_of_numbs = new float[count];

		for (int i = 0; i < count; i++)
		{

			arr_of_numbs[i] = temp_arr[i];

		}

		delete[] temp_arr;

	}

	return arr_of_numbs;

}

//Вывод в консоль введенного массива

void f_out_arr(const float* arr_of_numbs, const int& arr_count)
{

	cout << "Введнный массив данных:" << endl;
	cout << endl;

	for (int i = 0; i < arr_count; i++)
	{

		cout << i << "й эл.    " << arr_of_numbs[i] << endl;

	}

	cout << endl;

}

//Умножение положительных элементов

double f_positive_multi(const float* arr_of_numbs, int const& len)
{

	int count = 0;
	double res0 = 1;

	for (int i = 0; i < len; i++)
	{

		if (arr_of_numbs[i] > 0)
		{

			count++;

			res0 = res0 * arr_of_numbs[i];

		}

	}

	if (count == 0)
	{

		return 0;

	}

	return res0;

}

//Сумма элементов до минимума массива

double f_sum_until_min(const float* arr_of_numbs, int const& len)
{

	double res0 = 0;
	float min = arr_of_numbs[0];
	int pos = 0;

	for (int i = 1; i < len; i++)
	{

		if (min > arr_of_numbs[i])
		{

			min = arr_of_numbs[i];
			pos = i;

		}

	}

	if (pos == 0)
	{

		return 0;

	}

	else
	{

		for (int i = 0; i < pos; i++)
		{

			res0 += arr_of_numbs[i];

		}

	}

	return res0;

}

//Функция сортировки массива

void f_sort(float* arr_of_numbs, int const& len)
{

	for (int i = 0; i < len; i++)
	{

		for (int j = 0; j < len - 2; j++)
		{

			if (arr_of_numbs[j + 2] < arr_of_numbs[j])
			{

				float temp = arr_of_numbs[j];
				arr_of_numbs[j] = arr_of_numbs[j + 2];
				arr_of_numbs[j + 2] = temp;

			}

		}

	}

}

//Функция вывода результатов

void f_output(const float* arr_of_numbs, const int& arr_count, const double& sum, const double& multiple)
{

	cout << endl;

	if (multiple == 0)
	{

		cout << "Положительных элементов в массиве чисел нет!!! Произведение равно 0." << endl;

	}

	else
	{

		cout << "Произведение положительных элементов массива равно: "
			<< multiple << endl;

	}

	cout << endl;

	if (sum == 0)
	{

		cout << "Сумма до минимума массива равна 0. Так как 0й элемент массива является самым минимальным числом." << endl;

	}

	else
	{

		cout << "Сумма до минимума массива равна: " << sum << endl;

	}

	cout << endl;

	cout << "Отсортированный массив(Отдельно по возрастанию для четных и нечетных):" << endl;
	cout << endl;

	for (int i = 0; i < arr_count; i++)
	{

		cout << i << "й эл.    " << arr_of_numbs[i] << endl;

	}

}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr_len = 4;
	int arr_count = 0;
	double multiple = 0;
	double sum = 0;

	float* arr_of_numbs = f_input_arr(arr_len, arr_count);	//ВВод массива

	f_out_arr(arr_of_numbs, arr_count);						//Вывод в консоль введенного массива

	multiple = f_positive_multi(arr_of_numbs, arr_count);	//Умножение положительных элементов

	sum = f_sum_until_min(arr_of_numbs, arr_count);			//Сумма элементов до минимума массива

	f_sort(arr_of_numbs, arr_count);						//Функция сортировки массива

	f_output(arr_of_numbs, arr_count, sum, multiple);		//Функция вывода результатов

	delete[] arr_of_numbs;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");
}
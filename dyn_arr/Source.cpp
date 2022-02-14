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

//���� �������

float* f_input_arr(int& len, int& count)
{

	float numb = 0;
	bool check = true;
	float* arr_of_numbs = new float[len];

	cout << "������� ������ ������������ �����: " << endl;

	

	//���� ����� �������

	do
	{

		if (count >= len)		//��������� ������ ��� ������������� �������
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

		cout << count << "� �������: ";
		cin >> numb;
		cout << endl;

		while (!cin.good() || cin.peek() != '\n')		//�������� ������������ �������� ������
		{

			cerr << "������������ ���� ������!!!" << endl;
			cout << "�������� ������� ������ ���� ������. ������� ����� ������ ���� �������� ������!!!" << endl;
			cout << "��������� ����!!!" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << count << "� �������: ";
			cin >> numb;
			cout << endl;

		}

		arr_of_numbs[count] = numb;

		cout << "���������� ���� ���������? (1 - �� / 0 - ���)" << endl;
		cin >> check;
		cout << endl;

		while (!cin.good() || cin.peek() != '\n')		//�������� ������������ ���������� �����
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cerr << "������������ ����!!!" << endl;
			cout << "������� 1 - ��� ����������� ����� ���������, ���� 0 - ��� ���������� �����!!!" << endl;
			cin >> check;
			cout << endl;

		}

		count++;

	} while (check == true);		//������� ������ �� ����� ����� ���������

	if (count < len)				//��������� ������������� �������
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

//����� � ������� ���������� �������

void f_out_arr(const float* arr_of_numbs, const int& arr_count)
{

	cout << "�������� ������ ������:" << endl;
	cout << endl;

	for (int i = 0; i < arr_count; i++)
	{

		cout << i << "� ��.    " << arr_of_numbs[i] << endl;

	}

	cout << endl;

}

//��������� ������������� ���������

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

//����� ��������� �� �������� �������

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

//������� ���������� �������

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

//������� ������ �����������

void f_output(const float* arr_of_numbs, const int& arr_count, const double& sum, const double& multiple)
{

	cout << endl;

	if (multiple == 0)
	{

		cout << "������������� ��������� � ������� ����� ���!!! ������������ ����� 0." << endl;

	}

	else
	{

		cout << "������������ ������������� ��������� ������� �����: "
			<< multiple << endl;

	}

	cout << endl;

	if (sum == 0)
	{

		cout << "����� �� �������� ������� ����� 0. ��� ��� 0� ������� ������� �������� ����� ����������� ������." << endl;

	}

	else
	{

		cout << "����� �� �������� ������� �����: " << sum << endl;

	}

	cout << endl;

	cout << "��������������� ������(�������� �� ����������� ��� ������ � ��������):" << endl;
	cout << endl;

	for (int i = 0; i < arr_count; i++)
	{

		cout << i << "� ��.    " << arr_of_numbs[i] << endl;

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

	float* arr_of_numbs = f_input_arr(arr_len, arr_count);	//���� �������

	f_out_arr(arr_of_numbs, arr_count);						//����� � ������� ���������� �������

	multiple = f_positive_multi(arr_of_numbs, arr_count);	//��������� ������������� ���������

	sum = f_sum_until_min(arr_of_numbs, arr_count);			//����� ��������� �� �������� �������

	f_sort(arr_of_numbs, arr_count);						//������� ���������� �������

	f_output(arr_of_numbs, arr_count, sum, multiple);		//������� ������ �����������

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
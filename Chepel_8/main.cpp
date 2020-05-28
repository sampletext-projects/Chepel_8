#include <iomanip>
#include <iostream>

using namespace std;

void write_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << setprecision(2) << mas[i] << " ";
	}
	cout << endl;
}

void randomize(double* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		m[i] = rand() % 200 / 10.;
	}
}

int find_max_index(double* mas, int size)
{
	double max = mas[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
			index = i;
		}
	}
	return index;
}

double find_max(double* mas, int size)
{
	int index = find_max_index(mas, size);
	double max = mas[index];
	return max;
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(0));

	cout << "�����: ������ ���� ����������" << endl;
	cout << "��������� ��� ������ � �������� � ������� �������" << endl;

	int hours = 24;
	double* temps = new double[hours];
	double* humidities = new double[hours];
	randomize(temps, hours);
	randomize(humidities, hours);
	for (int i = 0; i < hours; i++)
	{
		humidities[i] *= 5; //��������� �� 20 �� 100
	}

	cout << "�����������: \n";
	write_mas(temps, hours);
	cout << "���������: \n";
	write_mas(humidities, hours);

	int max_temp_index = find_max_index(temps, hours);
	int max_hum_index = find_max_index(humidities, hours);
	int max_temp = find_max(temps, hours);
	int max_hum = find_max(humidities, hours);

	cout << "������������ ����������� �� " << max_temp_index << " ���: " << max_temp << "\n";
	cout << "������������ ��������� �� " << max_hum_index << " ���: " << max_hum << "\n";

	system("pause");

	return 0;
}

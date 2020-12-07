#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;


//****************

void fn_zad_6_1()
{
	fstream in;
	fstream out;
	int buf_int;

	vector<int> tab_1D_int;
	vector<vector<int>> tab_2D_int;
	int i, j;

	int max_pic_light = 0;
	int min_pic_light = 0;



	in.open("C:\\dane\\dane.txt", ios::in);
	out.open("C:\\dane\\wynik6.txt", ios::app);


	//wczytanie do tablicy
	i = 0;
	while (in >> buf_int)
	{
		i++;
		tab_1D_int.push_back(buf_int);

		if (i % 320 == 0)
		{
			tab_2D_int.push_back(tab_1D_int);
			tab_1D_int.clear();
		}
	}


	//obliczenia
	max_pic_light = tab_2D_int[0][0];
	min_pic_light = tab_2D_int[0][0];

	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 320; j++)
		{
			//max
			if (tab_2D_int[i][j] > max_pic_light)
			{
				max_pic_light = tab_2D_int[i][j];
			}

			//min
			if (tab_2D_int[i][j] < min_pic_light)
			{
				min_pic_light = tab_2D_int[i][j];
			}
		}
	}

	//podanie wyniku
	out << "wynik zad 6.1: " << endl;
	out << "pixel max jasnosc : " << max_pic_light << endl;
	out << "pixel max jasnosc : " << min_pic_light << endl;

	cout << "wynik zapisano do pliku wynik6.txt" << endl;


	in.close();
	out.close();

}


//**********************************
void fn_zad_6_2()
{
	fstream in;
	fstream out;
	int buf_int;

	vector<int> tab_1D_int;
	vector<vector<int>> tab_2D_int;

	int i, j;

	int count_rows_to_remove = 0;

	in.open("C:\\dane\\dane.txt", ios::in);
	out.open("C:\\dane\\wynik6.txt", ios::app);

	//wczytanie do tablicy 2D
	i = 0;
	while (in >> buf_int)
	{
		i++;
		tab_1D_int.push_back(buf_int);

		if (i % 320 == 0)
		{
			tab_2D_int.push_back(tab_1D_int);
			tab_1D_int.clear();
		}
	}



	//obliczenia
	count_rows_to_remove = 0;
	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 160; j++)
		{
			if (tab_2D_int[i][j] != tab_2D_int[i][319 - j])
			{
				count_rows_to_remove++;
				break;
			}
		}
	}


	//podanie wyniku
	out << "wynik zad. 6.2: " << endl;
	out << "ilosc wierszy do usunięcia : " << count_rows_to_remove << endl;

	cout << "wynik zapisano do pliku wynik6.txt" << endl;

	in.close();
	out.close();

}

//****************************
void fn_zad_6_3()
{
	fstream in;
	fstream out;
	int buf_int;

	vector<int> tab_1D_int;
	vector<vector<int>> tab_2D_int;

	int i, j;

	int counter;
	int count_contrast_pixel = 0;

	in.open("C:\\dane\\dane.txt", ios::in);
	out.open("C:\\dane\\wynik6.txt", ios::app);

	//wczytanie do tablicy 2D
	i = 0;
	while (in >> buf_int)
	{
		i++;
		tab_1D_int.push_back(buf_int);

		if (i % 320 == 0)
		{
			tab_2D_int.push_back(tab_1D_int);
			tab_1D_int.clear();
		}
	}



	//obliczenia
	counter = 0;
	count_contrast_pixel = 0;
	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 320; j++)
		{
			counter = 0;
			if (j + 1 < 320)
			{
				if (abs(tab_2D_int[i][j] - tab_2D_int[i][j + 1]) > 128)
				{
					counter++;
				}
			}

			if (j - 1 >= 0)
			{
				if (abs(tab_2D_int[i][j] - tab_2D_int[i][j - 1]) > 128)
				{
					counter++;
				}
			}

			if (i + 1 < 200)
			{
				if (abs(tab_2D_int[i][j] - tab_2D_int[i + 1][j]) > 128)
				{
					counter++;
				}
			}

			if (i - 1 >= 0)
			{
				if (abs(tab_2D_int[i][j] - tab_2D_int[i - 1][j]) > 128)
				{
					counter++;
				}
			}
			if (counter > 0)
			{
				count_contrast_pixel++;
			}
		}
	}


	//podanie wyniku
	out << "wynik zad. 6.3: " << endl;
	out << "ilość pixeli kontrastowych : " << count_contrast_pixel << endl;

	cout << "wynik zapisano do pliku wynik6.txt" << endl;

	in.close();
	out.close();

}


//****************************
void fn_zad_6_4()
{
	fstream in;
	fstream out;
	int buf_int;

	vector<int> tab_1D_int;
	vector<vector<int>> tab_2D_int;

	int i, j, k;

	int counter;
	int counter_max = 0;

	in.open("C:\\dane\\dane.txt", ios::in);
	out.open("C:\\dane\\wynik6.txt", ios::app);

	//wczytanie do tablicy 2D
	i = 0;
	while (in >> buf_int)
	{
		i++;
		tab_1D_int.push_back(buf_int);

		if (i % 320 == 0)
		{
			tab_2D_int.push_back(tab_1D_int);
			tab_1D_int.clear();
		}
	}



	//obliczenia
	counter_max = 0;
	for (j = 0; j < 320; j++)
	{
		i = 0;
		k = 0;
		counter = 0;
		while (i<200 and k<200)
		{
			if (tab_2D_int[i][j] == tab_2D_int[k][j])
			{
				counter++; 
				k++;
			}
			else
			{
				i = k;
				counter = 0;
			}

			if (counter > counter_max)
			{
				counter_max = counter;
			}
		}
	}




	//podanie wyniku
	out << "wynik zad. 6.4: " << endl;
	out << "najdluzsza linia pionowa : " << counter_max << endl;

	cout << "wynik zapisano do pliku wynik6.txt" << endl;

	in.close();
	out.close();
}



//****************************
int main()
{
	char opcja = ' ';

	while (opcja != 'x')
	{
		cout << endl << "wybierz opcje: 1- zad. 6.1 2- zad. 6.2 3- zad. 6.3 4- zad. 6.4 x- wyjscie" << endl;
		cin >> opcja;

		if (opcja == '1')
		{
			fn_zad_6_1();
		}
		else if (opcja == '2')
		{
			fn_zad_6_2();
		}
		else if (opcja == '3')
		{
			fn_zad_6_3();
		}
		else if (opcja == '4')
		{
			fn_zad_6_4();
		}


		else
			cout << "Bledna Opcja";
	}

	return 0;
}

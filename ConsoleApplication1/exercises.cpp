#include "exercises.h"
#include <string>
#include <istream>
#include <random>
#include <set>

template <typename T>
static T input(std::string& text)//функция ввода с встроенной обработкой исключений
{
	T digital=0;
	bool flag=true;
	do {
		cout << text;
		cin >> digital;
		flag = cin.good();
		//cout <<"cin.good()= " << cin.good()<<std::endl;
		if (!flag)
		{ 
			cout << "Error of input. Not a number. Enter num again.\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!flag);
	return digital;
}
template <typename T>
static T input(const char* text)//функция ввода с встроенной обработкой исключений
{
	T digital = 0;
	bool flag = true;
	do {
		cout << text;
		cin >> digital;
		flag = cin.good();
		//cout << "cin.good()= " << cin.good() << std::endl;
		if (!flag)
		{
			cout << "Error of input. Not a number. Enter num again.\n";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!flag);
	return digital;
}

static void exercise1()
{
	cout << "Hello exercise1\n";
	cout << "Enter quantity of X: ";
	int quantityOfX = 0;
	cin >> quantityOfX;
	double* valuesOfX = new double[quantityOfX];

	cout << "X = Z ^ 3 - B + A ^ 2 / tg betta ^ 2\n";
	double Z, B, A, b, Y;
	Y = 0.0;

	for (size_t i = 0; i < quantityOfX; i++)
	{
		cout << "Enter Z, B, A, betta \n";
		cout << "Z = ";
		cin >> Z;
		cout << "B = ";
		cin >> B;
		cout << "A = ";
		cin >> A;
		cout << "angle in radians betta = ";
		cin >> b;
		valuesOfX[i] = pow(Z, 3) - B + pow(A, 2) / pow(tan(b), 2);
		cout << "X #" << i << " = " << valuesOfX[i] << std::endl;
		Y += valuesOfX[i];
	}

	cout << "Y = " << Y;
	delete[] valuesOfX;
	return;
}

/*Найти алгебраическую сумму для выражения:
1k + 2k + 3k + … + Nk. N и степень k вводит пользователь.*/

static void exercise2() {
	cout << "Hello exercise-2\n";
	cout << "Enter quantity of numbers N:";
	int N = 0;
	cin >> N;
	cout << "Enter \"to the power of?\" k:";
	double k;
	cin >> k;
	double result = 0;
	for (size_t i = 1; i <= N; i++)
	{
		result += pow(i, k);
		cout << i <<"^"<<k<<"+ ";
	}
	cout << " = " << result;
}

/*Организовать ввод целого числа с клавиатуры.
Программа должна определить наименьшую и наибольшую цифры,
которые входят в состав данного натурального числа.*/

static void exercise3()
{
	const int SIZE = 10;// 10 цифр максимум в типе int
	cout << "Enter integer number: ";
	int number;
	short* figures = new short[SIZE];
	cin >> number;
	int copyNum=number;
	if (copyNum < 0) copyNum *= -1;
	clearArray(figures, SIZE);
	showArray(figures, SIZE);
	for (size_t i = 9; i > 0; i--)
	{
		figures[i] = copyNum % 10;
		copyNum /= 10;
		if (!copyNum) break;
	}
	showArray(figures, SIZE);
	cout << "Max figure: " << maxInArr(figures, SIZE) << std::endl;
	cout << "Min figure: " << minInArr(figures, SIZE) << std::endl;
	delete[] figures;
}

template <typename T>
void clearArray(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}

template <typename T>
void showArray(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << std::endl;
}

template <typename T>
T maxInArr(T* arr, int size)
{
	T max = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

template <typename T>
T minInArr(T* arr, int size)
{
	T min = 10;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == 0 && min == 10) continue;
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

/*Напишите программу , в которой по извесной начальной скорости V и времени полета тела T 
определяется угол aльфа под которым тело брошено по отношению к горизонту 
(воспользуйтесь соотношением a = arcsin(gT/2V) ).*/
static void exercise4()
{
	double timeOfFly = 0;
	double startSpeed = 0;
	const double g = 9.81;//acceleration of free falling.
	std::string text1= {"Enter time Of Fly: "};
	std::string text2= {"Enter start speed: "};
	timeOfFly= input<double>(text1);
	startSpeed=input<double>(text2);
	
	double a = 0;
	a = std::asin(g * timeOfFly / (2 * startSpeed))*180/M_PI;
	cout << "throw angle =" << a << std::endl;
}

/*по введенному номеру дня недели вывести его название, используя оператор множественного выбора.
Нумерация дней недели начинается с 1 – понедельник, 2 — вторник и т. д.*/

static void exercise5()
{
	cout << dayOfWeek(3)<<std::endl;
}
inline const char* dayOfWeek(int num)
{
	switch (num)
	{
	case 1:
		return "monday";
	case 2:
		return "tuesday";
	case 3:
		return "wednesday";
	case 4:
		return "thursday";
	case 5:
		return "friday";
	case 6:
		return "saturday";
	case 7:
		return "sunday";
	default:
		return "Error. Not from 1 to 7";
	}	
}

/*Напишите программу, которая позволяет пользователю ввести в консоль три координаты вектора x, y, и z,
с основанием у начала координат.Вычислите длину этого вектора и выведите её обратно в консоль*/

static void exercise6()
{
	double x = input<double>("enter x: ");
	double y = input<double>("enter y: ");
	double z = input<double>("enter z: ");

	cout << "{ " << x << ", " << y << ", " << z << " }" << std::endl;
	double vectorLenght;
	vectorLenght = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	cout << "vectorLenght = " << vectorLenght << std::endl;
}

/*Вычислить, не используя функцию pow, значения функции z(x,m) = x^m sin^m(x*m), для значений аргументов:
x от -1.1 до 0.3 с шагом 0.2;
m от 1 до 5 с шагом 1.*/
static void exercise7()
{
	double x=-1.1;
	int m=1;

	while (x <= 0.3)
	{
		while (m <= 5)
		{
			cout << "z(x=" << x << ", m=" << m << ") = ";
			double xM = x;
			double sinMX = sin(x * m);
			for (size_t i = 1; i < m; i++)
			{
				xM *= x;
				sinMX*= sin(x * m);
			}
			m++;
			cout << xM * sinMX << std::endl;
		}
		m = 1;
		x += 0.2;
		cout << std::endl;
	}

}

/*Дан одномерный массив, длину массива задаёт пользователь.
Вычислить сумму квадратов тех чисел, модуль которых превышает значение 2,5.*/
static void exercise8()
{
	srand(time(NULL));
	double lower_bound = 0.0;
	double upper_bound = 5.0;
	std::uniform_real_distribution<double> doubleRand(lower_bound, upper_bound);
	std::default_random_engine re;

	int size = input<int> ("Enter length of array: ");
	double* array = new double[size];
	
	for (size_t i = 0; i < size; i++)
	{
		array[i] = doubleRand(re);
	}
	showArray(array, size);
	
	double result = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (abs(array[i]) >= 2.5)
		{
			cout << array[i] << "^2 + ";
			result += array[i] * array[i];
		}
	}
	if (result != 0) cout << "\b\b= " << result << std::endl;
	else cout << "All numbers are less than 2.5\n";
	delete[] array;
}

/*Вычислить значение выражения по формуле (все переменные принимают действительные значения): 
(1-tg x)^(ctg x)+ cos(x-y).*/
static void exercise9()
{
	double x = input<double>("Enter x: ");
	double y = input<double>("Enter y: ");
	cout << "(1-tg x)^(ctg x)+ cos(x-y) = ";
	cout << pow((1 - tan(x*M_PI / 180)), 1 / tan(x* M_PI / 180)) + cos((x - y)* M_PI / 180) << std::endl;
}

/*Запрограммировать генератор псевдослучайных чисел, 
используя конгруэнтный метод формирования псевдослучайных чисел.*/

static void exercise10()
{
	cout << "congruental numbers: ";
	int startNum = 67;// начальное значение (выбирается случайно 0 <= x0 < m)
	for (int i = 0; i < 25; i++)
	{
		cout << congruential(startNum) << ' ';
	}
}
inline double congruential(int& x) // функция генерации псевдослучайных чисел
{
	const int m = 100, // генерация псевдослучайных чисел в диапазоне значений от 0 до 100 (выбирается случайно m > 0)
		a = 8, // множитель (выбирается случайно 0 <= a <= m)
		inc = 65; // инкрементирующее значение (выбирается случайно 0 <= inc <= m)
	x = ((a * x) + inc) % m; // формула линейного конгруэнтного метода генерации псевдослучайных чисел 
	return (x / double(m));
}

/*Определить номер четверти плоскости, в которой находится точка с координатами X и Y , 
причем XY != 0. Координаты вводить с клавиатуры.*/

static void exercise11()
{
	cout << "coordinate plane quarter\n";
	double x = input<double>("Enter X: ");
	double y = input<double>("Enter Y: ");

	if (x == 0 && y == 0) cout << "point O (0; 0)";
	else if (x > 0)
		if (y > 0) cout << "1st quarter";
		else if (y <0) cout << "4rd quarter";
		else cout << "point on OX axis X>0";

	else if (x <0)
		if (y > 0) cout << "2nd quarter";
		else if (y <0) cout << "3rd quarter";
		else cout << "point on OX axis X<0";

	else if (y>0) cout << "point on OY axis Y>0";
	else cout << "point on OY axis Y<0";
	cout << std::endl;
}

/*Составить алгоритм определяющий, 
есть ли среди цифр введенного трехзначного числа — одинаковые. Число вводится с клавиатуры.*/

static void exercise12() {
	const int SIZE = 10;// 10 цифр максимум в типе int.
	int number = input<int>("Enter integer number: ");
	short* figures = new short[SIZE];
	int copyNum = number;

	if (copyNum < 0) copyNum *= -1;
	clearArray(figures, SIZE);
	//showArray(figures, SIZE);
	for (size_t i = SIZE-1; i >= 0; i--)
	{
		figures[i] = copyNum % 10;
		copyNum /= 10;
		if (!copyNum) break;
	}
	//showArray(figures, SIZE);
	std::set<short> myset;//множество для проверки наличия одинаковых цифр.
	std::set<short> equals;// множество чтобы сложить в него повторные числа для вывода на экран в конце.

	bool flag = false;
	short quantityOfFigures=0;
	short quantityOfEquals=0;
	for (size_t i = 0; i < SIZE; i++)
	{
		if (!flag)// в начале если встречаем нуль -> пропускаем итерацию цикла.
			if (figures[i] == 0) continue;
			else flag = true;
		myset.insert(figures[i]);
		quantityOfFigures++;
		if (myset.size() + quantityOfEquals != quantityOfFigures)
		{
			equals.insert(figures[i]);
			quantityOfEquals++;
		}
	}
	cout << std::endl;
	cout << "in your number:" << quantityOfFigures << " figures\n";
	if (myset.size() == quantityOfFigures) cout << "there are no equal figures";
	else
	{
		cout << "your number contains equal figures: ";
		for (short elem : equals)
		{
			cout << elem << " ";
		}
	}
	cout <<"\n" << number;
	cout << std::endl;
}


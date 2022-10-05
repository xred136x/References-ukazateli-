// шаблон
#include<iostream>
using namespace std;

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void pswap(int* pn1, int* pn2) {
	int tmp = *pn1;
	*pn1 = *pn2;
	*pn2 = tmp;
}

void refswap(int refn1, int refn2) {
	int tmp = refn1;
	refn1 = refn2;
	refn2 = tmp;
}

int mx[10][2];

int& func(int index) {
	return mx[index][1];
}


template<typename T>
void fill_arr(T arr[], const int len, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (end - begin) + begin;
}

void show_arr(int arr[], const int len) {
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
}
template<typename T>
T& max_arr(T arr[], const int len) {
	int i_max = 0;
	for (int i = 1; i < len; i++)
		i_max = arr[i] > arr[i_max] ? i : i_max;
	return arr[i_max];
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10, m = 20;
	// нейтральный указатель

	/*//int* pn = 0;// первый способ
	//int* pn = NULL;// второй способ
	int* pn = nullptr; // третий способ
	pn = &n;

	if (pn == nullptr)
		cout << "указатель неинициализирован\n";
	else
		cout << *pn << '\n';*/

	int a = 10, b = 20, c = 30;
	// указатель на константу. используя разыменование нельзя поменять значение переменной, на которую указывает
	/*int const* pa;
	pa = &a;
	cout << *pa << '\n';
	pa = &b;
	cout << *pa << '\n';
	//*pa = 15;// ошибка*/

	// константный указатель
	/*const int* pb;
	pb = &b;
	cout << *pb << '\n';
	pb = &c;
	cout << *pb << '\n';
	//*pb = 35;// ошибка*/

	// Константный указатель на константу
	// нельзя менять значение переменной, а так же перенаправить указатель
	/*const int* const pc = &c;
	cout << *pc << '\n';
	//pc = &a;// ошибка
	//*pc = 35;// ошибка*/
	// Ссылка на переменную
	/*int& refn = n;// создаем ссылку связанную с переменной n
	cout << "n = " << n << '\n';
	cout << "refn = " << refn << '\n';
	refn = 15;
	cout << refn << '\n';*/
	// Ссылки как параметры функции
	/*cout << n << ' ' << m << '\n';
	//my_swap(n, m);// удобно, но не работает
	//pswap(&n, &m);// работает, но не удобно
	refswap(n, m);
	cout << n << ' ' << m << '\n';*/

	/*for (int i = 0; i < 10; i++) {
		cout << "ряд № " << i + 1 << ": ";
		cin >> mx[i][0];
		func(i) = mx[i][0];
	}
	cout << "итоговый массив: \n";
	for (int i = 0; i < 10; i++)
		cout << mx[i][0] << '\t' << func(i) << '\n';*/

	const int size = 5;
	int arr[size]{ 4, 2, 7, 1, 6 };
	cout << "изначальный массив:\n";
	show_arr(arr, size);
	cout << "\nмакс = " << max_arr(arr, size) << '\n';
	cout << "обнуляем макс...\nИтоговый массив:\n";
	max_arr(arr, size) = 0;
	show_arr(arr, size);


	return 0;
}
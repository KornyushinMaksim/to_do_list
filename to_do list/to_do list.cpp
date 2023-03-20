//Создайте приложение «Список дел».
//Приложение должно позволять :
//■ Добавление дел.У дела есть :
//•название;
//•приоритет;
//•описание;
//•дата, время исполнения.
//■ Удаление дел.
//■ Редактирование дел.
//■ Поиск дел по :
//•названию;
//•приоритету;
//•описанию;
//•дате и времени исполнения.
//■ Отображение списка дел :
//•на день;
//•на неделю;
//•на месяц.
//■ При отображении должна быть возможность сортировки :
//•по приоритету;
//•по дате и времени исполнения.

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct date {
	int day;
	int month;
	double time;
};
struct to_do {
	char name[40];
	char priority[4];
	char description[300];
	date performance;
};
void add(to_do*& list, int& size) {
	to_do* new_list = new to_do[size + 1];
	for (int i = 0; i < size; i++) {
		new_list[i] = list[i];
	}
	cin.getline(new_list[size].name, 40); //bag
	cout << "Название: ";
	cin.getline(new_list[size].name, 40);
	cout << "Приоритет: ";
	cin.getline(new_list[size].priority, 4);
	cout << "Описание: ";
	cin.getline(new_list[size].description, 100);
	cout << "День исполнения: ";
	cin >> new_list[size].performance.day;
	cout << "Месяц исполнения: ";
	cin >> new_list[size].performance.month;
	cout << "Время исполнения: ";
	cin >> new_list[size].performance.time;
	delete[] list;
	size++;
	list = new_list;
}
void print(to_do*& list, int& size) {
	system("cls");
	cout << "Общий список дел : \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ".\n"
			<< list[i].name << "\t\tПриоритет: "
			<< list[i].priority << endl << "дата "
			<< list[i].performance.day << "."
			<< list[i].performance.month << "\tвремя "
			<< list[i].performance.time << endl << endl
			<< list[i].description << endl
			<< "--------------------" << endl;
	}
	cout << "1. Отображение списка на день\n2. Отображение списка на неделю\n3. Отображение списка на месяц\n";

}
void print_name(to_do*& list, int& size) {
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << list[i].name << endl;
	}
}
void print_delo(to_do*& list, int delo) {
	cout << endl
		<< "--------------------" << endl
		<< delo << ".\n"
		<< list[delo - 1].name << "\t"
		<< list[delo - 1].priority << endl << "число "
		<< list[delo - 1].performance.day << "/"
		<< list[delo - 1].performance.month << "\tвремя "
		<< list[delo - 1].performance.time << endl << endl
		<< list[delo - 1].description << endl
		<< "--------------------" << endl;

}
void del(to_do*& list, int& size) {
	print_name(list, size);
	to_do* new_list = new to_do[size - 1];
	cout << "Выберите номер дела для удаления: ";
	int a;
	cin >> a;
	for (int i = 0; i < a - 1; i++) {
		new_list[i] = list[i];
	}
	for (int i = a; i < size; i++) {
		new_list[i - 1] = list[i];
	}
	delete[] list;
	size--;
	list = new_list;
}
void edit(to_do*& list, int& size) {
	system("cls");
	print_name(list, size);
	cout << "Выберите номер дела для редактирования: ";
	int delo;
	cin >> delo;
	print_delo(list, delo);
	int punkt;
	bool flag = true;
	while (flag) {
		cout << "1. Название\n2. Приоритет\n3. Описание\n4. День\n5. Месяц\n6. Время\n7. Завершить редактирование\nВыберите пункт для редактирования:\n";
		cin >> punkt;
		system("cls");
		switch (punkt) {
		case 1:
			cin.getline(list[delo - 1].name, 40); //bag
			cout << "Название: ";
			cin.getline(list[delo - 1].name, 40);
			print_delo(list, delo);
			break;
		case 2:
			cin.getline(list[delo - 1].priority, 4); //bag
			cout << "Приоритет: ";
			cin.getline(list[delo - 1].priority, 4);
			print_delo(list, delo);
			break;
		case 3:
			cin.getline(list[delo - 1].priority, 4); //bag
			cout << "Описание: ";
			cin.getline(list[delo - 1].description, 100);
			print_delo(list, delo);
			break;
		case 4:
			cout << "День исполнения: ";
			cin >> list[delo - 1].performance.day;
			print_delo(list, delo);
			break;
		case 5:
			cout << "Месяц исполнения: ";
			cin >> list[delo - 1].performance.month;
			print_delo(list, delo);
			break;
		case 6:
			cout << "Время исполнения: ";
			cin >> list[delo - 1].performance.time;
			print_delo(list, delo);
			break;
		case 7:
			flag = false;
		}
		system("pause");
	}
}

int main()
{
	system("chcp 1251>nul");
	int size = 4;
	to_do* list = new to_do[size];
	list[0] = { "Магазин","2","Квас, укроп, огурец",3,4,17.30 };
	list[1] = { "Гараж","1","Уборка, покраска ворот",7,8,12.10 };
	list[2] = { "Поезд","5","Чемодан, паспорт, билеты, бетерброд, вода",8,4,5.05 };
	list[3] = { "Стоматолог","3","Паспорт, кредитка, вода",7,8,18.15 };
	while (true) {
		cout << "Меню: \n1. Добавить \n2. Удалить\n3. Редактировать\n4. Поиск\n5. Отображение списка дел\n6. Сортировка по приоритету\n7. Сортировка по дате\n";
		char pos;
		cin >> pos;
		switch (pos) {
		case '1':
			add(list, size);
			break;
		case '2':
			del(list, size);
			break;
		case '3':
			edit(list, size);
			break;
		case '5':
			print(list, size);
			break;
		}
		//system("cls");
		//print_name(list, size);
		system("pause");
	}

}


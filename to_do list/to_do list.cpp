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
	int hours;
	int minets;
};
struct to_do {
	char name[40];
	char priority[4];
	char description[300];
	date performance;
};

void print_name(to_do*& list, int& size) {
	cout << "Общий список дел : \n";
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << list[i].name << endl;
	}
}
//void print_delo(to_do*& list, int delo) {
//	cout << endl
//		<< "--------------------" << endl
//		<< delo << ".\n"
//		<< list[delo - 1].name << "\t"
//		<< list[delo - 1].priority << endl << "дата "
//		<< list[delo - 1].performance.day << "."
//		<< list[delo - 1].performance.month << "\tвремя "
//		<< list[delo - 1].performance.time << endl << endl
//		<< list[delo - 1].description << endl
//		<< "--------------------" << endl;
//
//}
void show_delo(to_do*& list, int index) {
	cout << "--------------------" << endl
		<< index + 1 << ".\n"
		<< list[index].name << "\t\tПриоритет: "
		<< list[index].priority << endl << "дата "
		<< list[index].performance.day << "."
		<< list[index].performance.month << "\tвремя "
		<< list[index].performance.hours << ":"
		<< list[index].performance.minets << endl << endl
		<< list[index].description << endl
		<< "--------------------" << endl;
}

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
	cout << "Час исполнения: ";
	cin >> new_list[size].performance.hours;
	cout << "Минуты исполнения: ";
	cin >> new_list[size].performance.minets;
	delete[] list;
	size++;
	list = new_list;
}
void print(to_do*& list, int& size) {
	system("cls");
	cout << "Общий список дел : \n";
	for (int i = 0; i < size; i++) {
		cout << "--------------------" << endl
			<< i + 1 << ".\n"
			<< list[i].name << "\t\tПриоритет: "
			<< list[i].priority << endl << "дата "
			<< list[i].performance.day << "."
			<< list[i].performance.month << "\tвремя "
			<< list[i].performance.hours << ":"
			<< list[i].performance.minets << endl << endl
			<< list[i].description << endl
			<< "--------------------" << endl;
	}
	bool flag = true;
	while (flag) {
		cout << "Отображение списка:\n1. на день\n2. на неделю\n3. на месяц\n4. Завершить\n";
		int a;
		cin >> a;
		system("cls");
		switch (a) {
		case 1:
			cout << "Введите интересующий вас день: ";
			int day;
			cin >> day;
			for (int i = 0; i < size; i++) {
				if (list[i].performance.day == day) {
					show_delo(list, i);
				}
			}
			break;
		case 2:
			cout << "Введите интересующий вас неделю: "; //доделать
			break;
		case 3:
			cout << "Введите интересующий вас месяц: ";
			int month;
			cin >> month;
			for (int i = 0; i < size; i++) {
				if (list[i].performance.month == month) {
					show_delo(list, i);
				}
			}
			break;
		case 4:
			flag = false;
		}
	}
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
	cout << endl << "Выберите номер дела для редактирования: ";
	int delo;
	cin >> delo;
	show_delo(list, delo - 1);
	int punkt;
	bool flag = true;
	while (flag) {
		cout << "1. Название\n2. Приоритет\n3. Описание\n4. День\n5. Месяц\n6. Часы\n7. Минуты8. Завершить редактирование\nВыберите пункт для редактирования:\n";
		cin >> punkt;
		system("cls");
		switch (punkt) {
		case 1:
			cin.getline(list[delo].name, 40); //bag
			cout << "Название: ";
			cin.getline(list[delo - 1].name, 40);
			show_delo(list, delo - 1);
			break;
		case 2:
			cin.getline(list[delo - 1].priority, 4); //bag
			cout << "Приоритет: ";
			cin.getline(list[delo - 1].priority, 4);
			show_delo(list, delo - 1);
			break;
		case 3:
			cin.getline(list[delo - 1].priority, 4); //bag
			cout << "Описание: ";
			cin.getline(list[delo - 1].description, 100);
			show_delo(list, delo - 1);
			break;
		case 4:
			cout << "День исполнения: ";
			cin >> list[delo - 1].performance.day;
			show_delo(list, delo - 1);
			break;
		case 5:
			cout << "Месяц исполнения: ";
			cin >> list[delo - 1].performance.month;
			show_delo(list, delo - 1);
			break;
		case 6:
			cout << "Часы исполнения: ";
			cin >> list[delo - 1].performance.hours;
			show_delo(list, delo - 1);
			break;
		case 7:
			cout << "Минуты исполнения: ";
			cin >> list[delo - 1].performance.minets;
			show_delo(list, delo - 1);
			break;
		case 8:
			flag = false;
		}
		//system("pause");
	}
}
void search(to_do*& list, int& size) {
	system("cls");
	bool flag = true;
	while (flag) {
		cout << "Поиск дел по:\n1. названию\n2. приоритету\n3. описанию\n4. Завершить\n"
			<< "Выберите нужный пунк поиска: ";
		int a, 
			count = 0;
		cin >> a;
		switch (a) {
		case 1:
			cout << "Введите название для поиска: ";
			char search[40];
			cin.getline(search, 40); //bag
			cin.getline(search, 40);
			for (int i = 0; i < size; i++) {
				if (strstr(list[i].name, search)) {
					count++;
					show_delo(list, i);
					cout << endl;
				}

			}
			if (count == 0) {
				cout << "Совпадений не найдено" << endl;
			}
		case 4:
			flag = false;
		}
	}
}

int main()
{
	system("chcp 1251>nul");
	int size = 4;
	to_do* list = new to_do[size];
	list[0] = { "Магазин","2","Квас, укроп, огурец",3,4,17,30 };
	list[1] = { "Гараж","1","Уборка, покраска ворот",7,8,12,10 };
	list[2] = { "Поезд","5","Чемодан, паспорт, билеты, бутерброд, вода",8,4,5,05 };
	list[3] = { "Стоматолог","3","Паспорт, кредитка, вода",7,8,18,15 };
	while (true) {
		cout << "Меню: \n1. Добавить \n2. Удалить\n3. Редактировать\n4. Поиск\n5. Отображение списка дел\n6. Сортировка по приоритету\n7. Сортировка по дате\n\n";
		print_name(list, size);
		int pos;
		cin >> pos;
		switch (pos) {
		case 1:
			add(list, size);
			break;
		case 2:
			del(list, size);
			break;
		case 3:
			edit(list, size);
			break;
		case 4:
			search(list, size);
			break;
		case 5:
			print(list, size);
			break;
		}
		//system("cls");
		//system("pause");
	}

}

// доработать ввод приоритете (диапазон и защита от "дурака")
//доработать структуру "дата"
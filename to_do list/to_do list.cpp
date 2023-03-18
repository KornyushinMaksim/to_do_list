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
using namespace std;

struct date {
    int day;
    int month;
    float time;
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
    for (int i = 0; i < size; i++) {
        cout << i + 1<< ".\n"
            << list[i].name << "\t"
            << list[i].priority << endl << "число "
            << list[i].performance.day << "/"
            << list[i].performance.month << "\tвремя "
            << list[i].performance.time << endl
            << list[i].description << endl
            << "--------------------" << endl;
    }
}
void del(to_do*& list, int& size) {
    print(list, size);
    to_do* new_list = new to_do[size - 1];
    cout << "Выбирите номер дела для удаления: ";
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

int main()
{
    system("chcp 1251>nul");
    int size = 0;
    to_do* list = new to_do[size];
    while (true) {
    cout << "Меню: \n1. Добавить \n2. Удалить\n3. Редактировать\n4. Поиск\n5. Отображение списка дел\n6. Сортировка по приоритету\n7. Сортировка по дате\n";
    char pos;
    cin >> pos;
    switch (pos) {
    case '1':
        add(list, size);
        break;
    case '5':
        cout << "1. Отображение списка на день\n2. Отображение списка на неделю\n3. Отображение списка на месяц\n\nОбщий список дел:\n";
        print(list, size);
        break;
    case '2':
        del(list, size);
        break;
    }
        system("cls");
        //add(list, size);
        print(list, size);
        system("pause");
    }

}


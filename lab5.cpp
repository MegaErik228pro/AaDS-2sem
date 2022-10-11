#// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct List {
	string name;
	string info;
	List* next;
};

void menu();
void insert(string name, string info, List*& t);
void print_all(List* t);
void search(List* t, string name);
void del(List*& t, string name, int& all);

int main() {
	int all = 0;
	string name, info;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	List* start = NULL;
	int choice = 0;
	menu();
	do {
		cin >> choice;
		switch (choice) {
		case 1:
			cin >> name >> info;
			all++;
			insert(name, info, start);

			menu();
			break;
		case 2:
			print_all(start);
			menu();
			break;
		case 3:
			cin >> name;
			search(start, name);
			menu();
			break;
		case 4:
			cin >> name;
			del(start, name, all);
			break;
		case 5:
			cout << all << endl;
			break;
		case 6:
			break;
		default:
			break;
		}
	} while (choice < 6);
}

void menu(void) {
	cout << "1 - Поступление товара" << endl;
	cout << "2 - Список всех товаров" << endl;
	cout << "3 - Справка о конкретном товаре" << endl;
	cout << "4 - Выдача товара" << endl;
	cout << "5 - Количество всех товаров" << endl;
	cout << "6 - Выход" << endl;
}

void insert(string name, string info, List*& t) {
	List* f = new List;
	if (f != NULL) {
		f->name = name;
		f->info = info;
		f->next = t;
		t = f;
	}
	else {
		cout << "Операция не выполнена" << endl;
	}
}

void print_all(List* t) {
	if (t == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		while (t != NULL) {
			cout << t->name << endl;
			cout << t->info << endl << endl;
			t = t->next;
		}
	}
}

void search(List* t, string name) {
	if (t == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		while (t->name != name) {
			t = t->next;
		}
		cout << t->name << endl;
		cout << t->info << endl;
	}
}

void del(List*& t, string name, int& all) { // Передаем указатель  предыдущего звена, на это
	if (t == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		while (t->name != name) {
			t = t->next;
		}
		if (t->next) {
			t->name = t->next->name; // Или все скопировать с помощью memcpy
			t = t->next->next;
			delete t;
		}
		else { // Если этот узел последний
			t = NULL;
			delete t;
		}
	}
	all--;
}
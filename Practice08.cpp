#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Champion {
	string name;
	int health;
};

struct _ChampCompName {
	bool operator()(const Champion& c1, const Champion& c2) const { return (c1.name < c2.name); }
} ChampCompName;
//bool ChampCompHealth (const Champion& c1, const Champion& c2) { return (c1.name < c2.name); }
void sort_by_name(list<Champion> *lis) {
	lis->sort(ChampCompName);
}

void show_list(list<Champion> lis) {
	list<Champion> ::iterator iter;
	for (iter = lis.begin(); iter != lis.end() ; iter++)
	{
		cout << "(" << iter->name+ ", " << iter->health << ")-";
	} cout << endl;
}

void remove(string remo, list<Champion> *lis) {
	list<Champion> ::iterator iter;
	for (iter = lis->begin(); iter != lis->end(); iter++)
	{
		if (iter->name == remo) {
			lis->erase(iter);
			return;
		}
	}
}

list<Champion>::iterator operator+(const list<Champion>::iterator& p1, const int c) {
	list<Champion> ::iterator temp = p1;
	for (size_t i = 0; i < c; i++)
	{
		temp++;
	}
	return temp;
}

list<Champion>::iterator operator-(const list<Champion>::iterator& p1, const int c) {
	list<Champion> ::iterator temp = p1;
	for (size_t i = 0; i < c; i++)
	{
		temp--;
	}
	return temp;
}

int main() {
	string name_list[] = { "Vayne", "Mundo", "Elise", "Kayle" };
	double health_list[] = { 498, 582, 529, 574 };
	list<Champion> LIST;
	for (int i = 0; i < 4; i++)
	{
		Champion C = { name_list[i], health_list[i] };
		LIST.push_back(C);
	}
	show_list(LIST);

	Champion C = { string("Ashe"), 527 };
	LIST.insert(LIST.begin() + 2, C);
	show_list(LIST);
	
	Champion D = { string("Sona"), 482 };
	LIST.insert(LIST.end() - 1, D);
	show_list(LIST);
	
	sort_by_name(&LIST);
	show_list(LIST);
	
	remove("Mundo", &LIST);
    show_list(LIST);
	

}
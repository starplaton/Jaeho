#include <iostream>
#include <string>

using namespace std;

template<typename T, typename U>
class MyMap {
public:
	MyMap(int size = 1) {
		this->size = size;
		arrkey = new T[size];
		arrvalue = new U[size];
	}
	~MyMap() {}
	U *operator[](T const c) {
		for (int i = 0; i < size; i++)
		{
			if (c == arrkey[i]) return &arrvalue[i];
		}
		return NULL;
	}
	bool insert(T key2, U value2 ) {
		for (int i = 0; i < size; i++)
		{
				arrkey[seq] = key2;
				arrvalue[seq++] = value2;
				return true;
		}
		return false;
	}
private:
	T* arrkey;
	U* arrvalue;
	int seq = 0;
	int size = 0;
};


int main() {
	MyMap<string, int> M1(10); // 10 is the maximum size of the map
	M1.insert("one", 1);  M1.insert("two", 2); M1.insert("three", 3);
	if (M1["two"]) cout << *M1["two"] << endl;
	else cout << "No Match" << endl;
	if (M1["ten"]) cout << *M1["ten"] << endl;
	else cout << "No Match" << endl;
	MyMap<int, string> M2(10);
	M2.insert(10, "ten"); M2.insert(20, "twenty"); M2.insert(30, "thirty");
	if (M2[30]) cout << *M2[30] << endl;
	else cout << "No Match" << endl;
}
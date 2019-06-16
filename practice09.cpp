#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool read_a_word(ifstream& in, string& w) { 
	in >> w;
	return true;
};


template<template <typename> class P = less >

struct compare_pair_second {

	template<class T1, class T2> bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};

void ShowTop10(map<string, int> &m, vector<string> &arr) {
	vector< pair<string, int> > arr2;
	for (auto iter = m.begin(); iter != m.end(); ++iter) {
		arr2.emplace_back(make_pair(iter->first, iter->second));
	}
	sort(arr2.begin(), arr2.end(), compare_pair_second<std::less>());
	for (int i = 0; i < 10; i++)
	{
		cout << arr2.at(arr2.size()-1-i).first << " : " << m[arr2.at(arr2.size() - 1 - i).first] << endl;
	}
}


int main() {
	string word;
	ifstream in("text1.txt"); 
	if (!in.is_open()) exit(1);
	
	map<string, int> m;
	vector<string> arr;

	while (in >> word)
	{
		m[word]++;
		arr.push_back(word);
	}
	ShowTop10(m, arr);

	int counta = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (m[arr.at(i)] == 1) counta++;
	}
	cout << "한번만 나타나는 단어 수 : " <<  counta;;





	/*while (in >> word) {
	
		int loc = word.find(".");
		if (loc == 0) word = word.substr(1,word.length());
		if (loc == word.length()-1) word = word.substr(0,word.length() - 1);
		loc = word.find("\"");
		if (loc == 0) word = word.substr(1, word.length());
		if (loc == word.length() - 1) word = word.substr(0, word.length() - 1);

		//cout << word + " ";

		//arr.push_back(word);

	}
	sort(arr.begin(), arr.end());

	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		int counta = 1;
		if (arr.back().compare(arr.at(arr.size() - 3)) == 0) {
			counta++;
		}
		else {
			cout << arr.back() << " : " << counta << endl;
			counta = 0;
		}
		arr.pop_back();
	}

	
	cout << arr.back() << "    " << arr.at(arr.size()-2);*/
}
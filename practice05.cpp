#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int find_subseq(string genome, string subseq, int mm) {
	int pointer = 0;
	int result = 0;
	//cout << genome;
	while (pointer+subseq.length() <= genome.length()) {
		int counta = 0;
		for (int i = 0; i < subseq.length(); i++)
		{
			if (genome[i + pointer] != subseq[i]) counta++;
		}
		if (counta <= mm) result++;
		++pointer;
	}

	return result;
}

int main(int argc,char* argv[]) {

	ifstream infile("tp53.txt");
	if (!infile.is_open()) {
		cout << "cannot open file" << endl; exit(-1);
	}

	string line;
	string genome = "";
	while (getline(infile, line)) {
		if (line[0] != '>') genome += line;
	}
	infile.close();
	//cout << genome;
	int num[4] = { 0,0,0,0 };
	for (int i = 0; i < genome.length(); i++)
	{
		if (genome[i] == 'A') num[0]++;
		else if (genome[i] == 'C') num[1]++;
		else if (genome[i] == 'T') num[2]++;
		else if (genome[i] == 'G') num[3]++;
	}
	//for (int i = 0; i < 4; i++) cout << num[i] << " ";
	//cout << endl;

	vector<int> loc(genome.length());
	int nloc;
	string subseq = "TTCCTAGCG";
	int mm = 2;
	nloc = find_subseq(genome, subseq, mm);
	cout << "maches with " << subseq;
	cout << " allowing " << mm;
	cout << " mismatches are " << nloc << endl;

}
#include <iostream>
#include <time.h>
#include <thread>

using namespace std;

int power(int n, int r)
{
	int p = 1;
	for (size_t i = 0; i < r ; i++)
	{
		p *= n;
	}
	return p;
}
int sequential_find(int n)
{
	int num = 0;
	for (int i = 0; i <= n; i++)
	{
		int tmp = i, digit = 0, sum = 0;
		while (tmp != 0) {
			digit++; tmp /= 10;
		}
		tmp = i;
		while (tmp != 0) {
			int remainder = tmp % 10;
			sum += power(remainder, digit);
			tmp = tmp / 10;
		}
		if (sum == i) num++;
	}
	return num;
}

void finding(int start, int end, int *nprime)
{
	*nprime = 0;
	for (int i = start; i <= end; i++)
	{
		int tmp = i, digit = 0, sum = 0;
		while (tmp != 0) {
			digit++; tmp /= 10;
		}
		tmp = i;
		while (tmp != 0) {
			int remainder = tmp % 10;
			sum += power(remainder, digit);
			tmp = tmp / 10;
		}
		if (sum == i) (*nprime)++;
	}
}

int parallel_find(int n, int nthread) {
	int num = 0, nnari[4];
	thread works[4];
	int numlist[3] = { -1, n / 2,  n};
	for (int i = 0; i < nthread; i++)
	{
		works[i] = thread(finding, numlist[i] + 1, numlist[i + 1], &nnari[i]);
	}
	for (int i = 0; i < nthread; i++) works[i].join();
	for (int i = 0; i < nthread; i++) num += nnari[i];
	return num;
}

int main() {
	int n = 100000000, nnum;
	clock_t t;
	double te_seq, te_para;

	t = clock(); int num = sequential_find(n); te_seq = (double)(clock() - t) / (CLOCKS_PER_SEC);
	cout << "Sequential program finds " << num << " numbers in " << te_seq << "sec" << endl;
	
	int nthread = 2;
	t = clock(); num = parallel_find(n, nthread); te_para = (double)(clock() - t) / (CLOCKS_PER_SEC);
	cout << "Parallel program finds " << num << " numbers in " << te_para << "sec" << endl;

	cout << "x" << te_seq / te_para << " speed up using " << nthread << " threads" << endl;
	
	return 0;
}
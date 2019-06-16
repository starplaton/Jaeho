#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;

int M = 0;
int a=0, b=0, c=0;
int ans = MAXINT;
int visited[999];
void dfs(int aa, int bb, int cc, int MM);

int main()
{

	cout << "Amount of money?";
	cin >> M;
	if (M % 6 == 0) {
		ans = M / 6;
	}
	if (M % 6 == 1) {
		ans = M / 6 + 1;
	}
	if (M % 6 == 2) {
		ans = M / 6 + 1;
	}
	if (M % 6 == 3) {
		ans = M / 6 + 2;
	}
	if (M % 6 == 4) {
		ans = M / 6 + 1;
	}
	if (M % 6 == 5) {
		ans = M / 6 + 2;
	}
	cout << ans << " coins";

	Sleep(500000);

	return 0;
}

void dfs(int aa, int bb, int cc, int MM) {
	//cout << MM << endl;
	visited[MM] = aa + bb + cc;
	if (MM < 0)
		return;
	if (MM == 0) {
	ans = min(ans, aa + bb + cc);
	return;
	}
	if (visited[MM] != 0)
		if (visited[MM] < aa + bb + cc)
			return;

	for (size_t i = 3; i >= 1; i--)
	{
		switch (i) {
		case 1:
			if(MM-1 >= 0)
					dfs(aa + 1, bb, cc, MM - 1);
			break;
		case 2:
			if (MM - 4 >= 0)
					dfs(aa, bb+1, cc, MM - 4);
			break;
		case 3:
			if (MM - 6 >= 0)
					dfs(aa, bb, cc+1, MM - 6);
			break;

		default:
			break;
		}
	}
}


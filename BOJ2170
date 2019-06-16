#include <iostream>https://github.com/starplaton/Jaeho
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
const int INF = 1e9 + 1;
int main() {
	pair<int, int> map[1000000];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[i] = pair<int, int>(a, b);
	}
	
	sort(map, map+N);
	int result = 0, left = -INF, right = -INF;
	for (int i = 0; i < N; i++)
	{
		if (map[i].first > right) {
			result += right - left;
			right = map[i].second;
			left = map[i].first;
		}
		else {
			right = max(right, map[i].second);
		}
	}
	result += right - left;

	printf("%d", result);
}

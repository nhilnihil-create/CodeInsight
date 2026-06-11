#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

int N;
int x[100000];
int cnt[100000];
int best[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < N; i++) {
		cnt[i] = 0;
	}

	int ima_best = 1;
	int mokuhyou = 1;
	for (int i = 0; i < N; i++) {
		best[i] = ima_best;
		if (x[i] < mokuhyou) { 
			ima_best += 1; 
		}
		else {
			mokuhyou += 2;
		}
		
	}
	for (int i = 0; i < N; i++) {
		cnt[best[i] - 1] += 1;
	}

//	for (int i = 0; i < N; i++) {
//		cout << cnt[i] << " ";
//	}
//	cout << "\n";
	long long ans = 1;
	int p = 0;
	for (int i = 0; i < N; i++) {
		p += cnt[i];
		ans = (ans * (p - i)) % 1000000007;
	}
	cout << ans;

}
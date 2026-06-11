#include<iostream>
#include<set>

using namespace std;

long long ncr[55][55];

void precalc(){
	for(int n = 0; n < 51; ++n){
		for(int r = 0; r <= n; ++r){
			if(r == 0){
				ncr[n][r] = 1;
				continue;
			}
			ncr[n][r] = ncr[n-1][r-1] + ncr[n-1][r];
		}
	}
}

int main()
{
	precalc();
	int n, p;
	cin >>n >>p;
	
	int even = 0, odd = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >>a;
		if(a % 2 == 0)
			++even;
		else
			++odd;
	}

	long long we = 1LL << even;
	long long wo = 0, ans = 0;
	int st = 0;

	if(p == 0)
		st = 0;	
	else
		st = 1;
	
	
	for(int i = st; i <= odd; i += 2)
		wo += ncr[odd][i];
	ans = wo * we;
	cout <<ans <<'\n';

	return 0;
}

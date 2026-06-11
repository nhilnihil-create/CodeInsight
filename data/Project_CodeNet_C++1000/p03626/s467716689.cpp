#include<iostream>
#include<bitset>
#include<sstream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<stdio.h>

using namespace std;
long gcd(long x, long y){ if (x > y){ return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; } return x; }
long lcm(long x, long y){ return (x / gcd(x, y) * y); }

int main(void){

	long N; cin >> N;
	long res = 1;
	long mod = 1000000007;
	string S1, S2; cin >> S1 >> S2;

	for (int i = 0; i < N; i++){
		if (S1[i] == S1[i + 1]) {
			if (i == 0) res *= 6;
			if (i == 1) res *= 2;
			if (i > 1){
				if (S1[i - 1] == S1[i - 2]) res *= 3;
				else res *= 2;
			}
			i++; 
		}
		if (S1[i] == S2[i]){
			if (i == 0) res *= 3;
			if (i == 1) res *= 2;
			if (i > 1){
				if (S1[i - 1] == S1[i - 2]) res *= 1;
				else res *= 2;
			}
		}
		res %= mod;
	}

	cout << res << endl;

}
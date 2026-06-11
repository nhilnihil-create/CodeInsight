#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int K, S;
	cin >> K >> S;
	int ans = 0;
	for(int X = 0; X <= K; X++){
		for(int Y = 0; Y <= K; Y++){
			int Z = S - X - Y;
			if(0<=Z && Z <= K) ans++;
		}
	}
	cout << ans << endl;

}











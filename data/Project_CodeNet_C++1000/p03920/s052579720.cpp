#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;


ull gcd(ull a,ull b){
	if(!b) return a;
	return gcd(b,a%b);
}


int main(){
	int n;
	cin >> n;
	int table[n],cnt = 0,num = 1,memo = n;
	
	rep(i,0,n){
		cnt++;
		table[i] = num;
		
		if(num == cnt){
			cnt = 0;
			num++;
		}
	}
	
	while(memo){
		cout << table[memo-1] << endl;
		
		memo -= table[memo-1];
		
	}
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;


int MOD=1000000007;


int main() {
	int N,T;
	cin >> N >> T;
	int b=0,m=MOD,p=0,a;
	for(int i=0; i<N; i++){
		cin >> a;
		if(i){
			if(a-m==p)b+=1;
			else if(a-m>p){
				p=a-m;
				b=1;
			}
		}
		m=min(a,m);
	}
	cout << b << endl;
	
}

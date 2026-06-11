#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;

int main(){
	int i, j;
	string s;
	cin >> s;
	n = s.size();
	int ans=0, r=s.size()-2;
	for(i=n-2; i; i-=2){
		bool ok = 1;
		for(j=0;j<i/2;j++){
			if(s[j]!=s[j+i/2])ok=0;
		}if(ok){
			cout << i;
			return 0;
		}
	}return 0;
}
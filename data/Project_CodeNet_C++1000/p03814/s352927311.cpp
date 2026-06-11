#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)

string s;

int main(void){
	cin >> s;
	int a, z;
	int n = s.size();
	rep(i, n){
		if(s[i] == 'A'){
			a = i;
			break;
		}
	}
	rrep(i, n){
		if(s[i] == 'Z'){
			z = i;
			break;
		}
	}
	cout << z-a+1 << endl;
	return 0;
}

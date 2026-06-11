#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int n,w,t,e;
int main(){
	string s;
	cin >> s;
	rep(i,s.size()){
		if(s[i] == 'N') n++;
		if(s[i] == 'W') w++;
		if(s[i] == 'S') t++;
		if(s[i] == 'E') e++;
	}
	if((n != 0 && t == 0) || (n == 0 && t != 0) || (w != 0 && e == 0) || (w == 0 && e != 0)){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int n = s.size();
	if(s[0] == s.back()){
		if(n&1){
			cout<<"Second\n";
		}else{
			cout<<"First\n";
		}
	}else{
		if(n&1){
			cout<<"First\n";
		}else{
			cout<<"Second\n";
		}
	}

	return 0;
}
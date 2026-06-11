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

	string s; cin>>s;
	int n = s.size();
	for(int i = 1; i < n; i++){
		if(s[i] == s[i - 1]){
			cout<<i<<" "<<i + 1<<endl;
			exit(0);
		}
		if(i > 1 && s[i] == s[i - 2]){
			cout<<i - 1<<" "<<i + 1<<endl;
			exit(0);
		}
	}
	cout<<"-1 -1"<<endl;

	return 0;
}
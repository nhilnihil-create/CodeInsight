#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	char y;
	int ret=0;
	string s="CODEFESTIVAL2016";
	for (char &x : s) {
		cin>>y;
		if(x!=y) ret++;
	}
	cout<<ret<<"\n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	cout<<(s.substr(0,4)=="YAKI"?"Yes":"No")<<"\n";
	return 0;
}
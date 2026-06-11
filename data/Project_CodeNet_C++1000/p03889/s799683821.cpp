#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;cin >> s;
	string t=s;
	reverse(t.begin(),t.end());
	rep(i,t.size()){
		if(t.at(i)=='b') t.at(i)='d';
		else if(t.at(i)=='d') t.at(i)='b';
		else if(t.at(i)=='p') t.at(i)='q';
		else if(t.at(i)=='q') t.at(i)='p';
	}
	if(s==t) cout << "Yes" << endl;
	else cout << "No" << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	string s;
	cin>>s;
	if(s.length()<4)cout<<"No"<<endl;
	else if(s.substr(0,4)=="YAKI")cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
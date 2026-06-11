#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	bool E=0,W=0,N=0,S=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	switch(s[i]){
		case 'E':E=1;break;
		case 'W':W=1;break;
		case 'S':S=1;break;
		case 'N':N=1;break;
	}
	if(E==W&&S==N)cout<<"Yes";
	else cout<<"No";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int len;
int main()
{
	cin>>s1;
	s2=s1;
	len=s1.size();
	reverse(s1.begin(),s1.end());
	for(int i=0;i<len;i++){
		if(s1[i]=='b'){
			s1[i]='d';
		}
		else if(s1[i]=='d'){
			s1[i]='b';
		}
		else if(s1[i]=='p'){
			s1[i]='q';
		}
		else if(s1[i]=='q'){
			s1[i]='p';
		}
	}
	if(s1==s2) cout<<"Yes";
	else cout<<"No";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char a[111111];
bool ok(char a,char b)
{
	if(a=='q'&&b=='p') return 1;
	if(a=='p'&&b=='q') return 1;
	if(a=='b'&&b=='d') return 1;
	if(a=='d'&&b=='b') return 1;
	return 0;
}
stack <char> s;
int main()
{
	cin>>a;
	for(int i=0;i<(strlen(a)+1)/2;i++) s.push(a[i]);
	for(int i=(strlen(a)+1)/2;i<strlen(a);i++){
		if(!ok(s.top(),a[i])){
			cout<<"No"<<endl;return 0;
		}
		
		s.pop();
	}
	cout<<"Yes"<<endl;
	return 0;
}
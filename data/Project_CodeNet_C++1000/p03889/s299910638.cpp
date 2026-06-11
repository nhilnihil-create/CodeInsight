#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n,m;
	cin>>n;
	m=n;
	for(int i=0;i<n.length();++i){
		switch(m[n.length()-i-1]){
			case 'b':m[n.length()-i-1]='d';break;
			case 'd':m[n.length()-i-1]='b';break;
			case 'p':m[n.length()-i-1]='q';break;
			case 'q':m[n.length()-i-1]='p';break;
		}
		if(m[n.length()-i-1]!=n[i]){
			cout<<"No";return 0;
		}
	}
	cout<<"Yes";
}
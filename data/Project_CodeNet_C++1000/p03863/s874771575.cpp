#include<bits/stdc++.h>
#define ll long long 
#define qaq() for(int i=1;i<=n;i++)
using namespace std;
string s;
int main() {
	cin>>s;
	if(s[0]==s[s.length()-1]) {
		if(s.length()%2==0) {
			cout<<"First"<<endl;
			return 0;
		} else {
			cout<<"Second"<<endl;
			return 0;
		}
	} else {
		if(s.length()%2==0) {
			cout<<"Second"<<endl;
			return 0;
		} else {
			cout<<"First"<<endl;
			return 0;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i=s;i<=e;++i)
#define REP(i,s,e) for(int i=s;i>=e;--i)

string s;

int main(){
	int sum=0;
	cin>>s;
	if(s[0]=='C') sum++;
	if(s[1]=='O') sum++;
	if(s[2]=='D') sum++;
	if(s[3]=='E') sum++;
	if(s[4]=='F') sum++;
	if(s[5]=='E') sum++;
	if(s[6]=='S') sum++;
	if(s[7]=='T') sum++;
	if(s[8]=='I') sum++;
	if(s[9]=='V') sum++;
	if(s[10]=='A') sum++;
	if(s[11]=='L') sum++;
	if(s[12]=='2') sum++;
	if(s[13]=='0') sum++;
	if(s[14]=='1') sum++;
	if(s[15]=='6') sum++;
	cout<<16-sum<<endl;
	return 0;
}

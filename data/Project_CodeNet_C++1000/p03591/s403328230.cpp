#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
string S;
int main(){
	cin>>S;
	cout<<(S.substr(0,4)=="YAKI" ? "Yes" : "No")<<endl;
}
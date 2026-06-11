#include <bits/stdc++.h> 
#define forn(i,a,b) for(int i=a; i<=b; i++)
#define ford(i,a,b) for(int i=a; i>=b; i--)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int h,w;
	string s;
	cin>>h>>w;
	forn(i,1,h){
		cin>>s;
		cout<<s<<"\n"<<s<<"\n";
	}
	return 0;
}
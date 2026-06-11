#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	fastio
	string s;
	cin>>s;
	int start=s.find('A');
	int end;
	for(int i=s.size()-1;i>=0;--i){
		if(s[i]=='Z'){
			end=i;
			break;
		}
	}
	cout<<end-start+1;	
	return 0;
}
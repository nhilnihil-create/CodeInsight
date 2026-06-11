#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

string s;
cin>>s;

int diff = 0;
for(int i=1;i<s.length();i++){
	if(s[i] != s[i-1]){

		diff++ ;
	}
}
	
if(diff == 0)
	cout<<0;
else
	cout<<diff;
	
}


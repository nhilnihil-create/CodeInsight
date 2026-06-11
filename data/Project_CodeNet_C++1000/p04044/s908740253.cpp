#include<bits/stdc++.h>
using namespace std;
     
int main(){
ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int i,j,k,n,l;
	string a,v="";
	cin>>n>>l;
	vector<string> s;
	for(i=0;i<n;i++){
		cin>>a;
		s.push_back(a);
	}
    sort(s.begin(),s.end());
    for(i=0;i<n;i++){
    	v+=s[i];
	}
	cout<<v;
    	
}
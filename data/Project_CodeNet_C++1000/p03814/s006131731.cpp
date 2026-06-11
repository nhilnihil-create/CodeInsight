#include <bits/stdc++.h>
using namespace std;

string s;
int n, a=-1, z;

int main(){
	cin>>s;
	n=s.size();
	
	for(int i=0; i<n; i++){
		if(a==-1&&s[i]=='A') a=i;
		else if(s[i]=='Z') z=i;
	}
	cout<<z-a+1<<endl;
}

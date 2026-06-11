#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	string s1 = "CODEFESTIVAL2016";
	string s; cin>>s;
	int count=0;
	int n = s.length();
	for(int i=0;i<n;i++){
		if(s[i]!=s1[i]){
			count++;
		}
	}
	cout<<count<<endl;
}
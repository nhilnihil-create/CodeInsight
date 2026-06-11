#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v[66];
signed main(){

	string str;
	cin>>str;
	for(int i=0;i<str.size();i++) v[str[i]-'a'].push_back(i);
	for(int i=0;i<26;i++){
		if(v[i].size()>1){
			for(int j=1;j<v[i].size();j++){
				if(v[i][j]-v[i][j-1]<=2){
					cout<<v[i][j-1]+1<<" "<<v[i][j]+1;
					return 0;
				}
			}
		}
	}
	cout<<"-1 -1";
	return 0;
}
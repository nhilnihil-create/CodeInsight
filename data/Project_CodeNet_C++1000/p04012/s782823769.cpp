#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double
#define ff first
#define ss second
int main(){
	string w; cin>>w;
	vector<int>a(26,0);
	for(int i=0;i<(int)w.length();++i){
		a[w[i]-'a']++;
	}
	bool ans=true;
	for(int i=0;i<26;++i){
		if(a[i]&1){
			ans=false;
			break;
		}
	}
	if(ans) printf("Yes\n");
	else printf("No\n");
	return 0;
}

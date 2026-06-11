#include<bits/stdc++.h>
using namespace std;
int main(){
	int H,W; cin>>H>>W;
	vector<string>a(H);
	map<char,int> cnt;
	int tot = H*W;
	for(int i=0;i<H;i++){
		cin>>a[i];
		for(int j=0;j<W;j++){
			cnt[a[i][j]]++;
		}
	}
	int two=0, one=0;
	for(int i=0;i<26;i++){
		if(cnt[i+'a']%2){
			one++, cnt[i+'a']--;
		}
	}
	if(one && H*W%2==0 || one>1){
		cout<<"No\n";
		return 0;
	}
	if(H%2) 
		two+=W/2;
	if(W%2) 
		two+=H/2;
	int four = (H*W-(H*W%2)-two * 2)/4;
	for(int i=0;i<26;i++){
		four -= cnt[i+'a']/4;
	}
	if(four>0) cout<<"No\n";
	else cout<<"Yes\n";
	return 0;
}
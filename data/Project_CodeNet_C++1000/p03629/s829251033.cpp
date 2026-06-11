#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define inf 1000000007
using namespace std;
signed main(){
	string s;
	cin>>s;
	set<char> moji;
	vector<int> cut;
	cut.pb(s.size());
	for(int i=s.size()-1;i>=0;i--){
		moji.insert( s[i] );
		if(moji.size() == 26){
			moji.clear();
			cut.pb(i);
		}
	}
	moji.clear();
	reverse(cut.begin(),cut.end());
	string str = "";
	int cur = 0;
	for(int i=0;i<cut.size();i++){
		moji.clear();
		char ta;
		for(int j=cur;j<cut[i];j++){
			moji.insert(s[j]);
		}
		for(int j=0;j<26;j++){
			if( moji.find( 'a' + j) == moji.end()){
				str.pb('a'+j);
				ta = 'a' + j;
				j = 26;
			}
		}
		cur = cut[i]+1;
		while( s[cur-1] != ta && cur<s.size()-1){ cur++; }
	}
	cout<<str<<endl;
	return 0;
}
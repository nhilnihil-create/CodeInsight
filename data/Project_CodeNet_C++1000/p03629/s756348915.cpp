#include "bits/stdc++.h"

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;cin>>s;
	bitset<32> bs(0);
	int len=s.length();
	vector<int> v(len+1,1);
	vector<vector<int>> p(26);
	for(int i=0;i<len;i++){
		int idx=s[i]-'a';
		p[idx].push_back(i);
	}
	for(int i=len-1;i>=0;i--){
		int idx=s[i]-'a';
		bs.set(idx);
		if(bs.count()==26){
			v[i]=v[i+1]+1;
			bs.reset();
		}
		else{
			v[i]=v[i+1];
		}
	}
	string res="";
	int cnt=v[0],pos=-1;
	for(int i=0;i<cnt;i++){
        char tmp='z'+1;
		int ptmp=pos;
		for(int j=0;j<26;j++){
			auto itr=upper_bound(p[j].begin(),p[j].end(),pos);
			if(itr==p[j].end()){
				tmp = (char)('a'+j);
				break;
			}
			int idx=*itr;
            //cout<<v[idx]<<" "<<cnt
			if(v[idx+1]==cnt-i-1){
				if(tmp>'z'){
					ptmp=idx;
					tmp = (char)('a'+j);
				}
			}
			continue;
		}
		pos=ptmp;
		res += tmp;
	}
	cout<<res<<endl;
}

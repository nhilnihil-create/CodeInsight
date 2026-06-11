#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s;cin>>s;
	int cnt=1e9;
	if(s.size()==1){
		cout<<0;
		return 0;
	}
	set<char>hnhn;
	for(char u:s)hnhn.insert(u);
	if(hnhn.size()==1){
		cout<<0;
		return 0;
	}
	string tmp;
	for(char c='a';c<='z';c++){
		tmp=s;
		int now=0;
		string t="";
		while(true){
			now++;
			for(int i=0;i<tmp.size()-1;i++){
				if(tmp[i]==c||tmp[i+1]==c){
					t+=c;
				}else{
					t+=tmp[i];
				}
			}
			set<char>ss;
			for(char u:t){
				ss.insert(u);
			}
			//cout<<t<<endl;
			//cout<<ss.size()<<endl;
			if(now>110)break;
			if(ss.size()==1){
				cnt=min(now,cnt);
				break;
			}
			tmp=t;
			t="";
			//cout<<111<<endl;
		}
	}
	cout<<cnt;
	return 0;
}
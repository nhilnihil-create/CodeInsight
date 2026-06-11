#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string>pl;
	map<char,int>discard;
	discard['a']=0;
	discard['b']=1;
	discard['c']=2;
	string s;
	char sl,t;
	for(int i=0;i<3;i++){
		cin>>s;
		pl.push_back(s);
	}
	sl='a';
	
	while(1){
		if(pl[discard[sl]].size()==0){
			cout<<char(t-32)<<endl;
			break;
		}
		t=pl[discard[sl]][0];
		
		pl[discard[sl]].erase(0,1);
		sl=t;
	}
	return 0;
}

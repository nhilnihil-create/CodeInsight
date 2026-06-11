#include <bits/stdc++.h>
using namespace std;
int main(){
		
		string str;cin>>str;
		int len = str.size();
		vector<int> v;
		v.push_back(3);
		for(int i=0;i<len;i++){
				if(str[i]=='B' && v.back()==3)continue;
				if(str[i]=='0')v.push_back(0);
				if(str[i]=='1')v.push_back(1);
				if(str[i]=='B'){
					v.pop_back();
					}
			}
		int s = v.size();	
		for(int i=1;i<s;i++){
				cout<<v[i];	
		}
		return 0;
	}

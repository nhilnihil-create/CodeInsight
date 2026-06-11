#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;cin>>s;
	int len = s.length();
	unordered_map <char,int> count(0);
	for(int i=0;i<len;i++){
			//~ if(count.find(s[i])==count.end())count[s[i]]++;
			//~ else count[s[i]]++;
			count[s[i]]++;
		}
	for(auto it=count.begin();it!=count.end();it++){
			if(it->second % 2 != 0){
					cout<<"No";
					return 0;
				}
		}	
	cout<<"Yes";	
	return 0;
	}

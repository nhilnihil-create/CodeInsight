#include<bits/stdc++.h>
using namespace std;
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // string s;
    // cin>>s;
   	// int flag=1;
    // for(int i=0;i<s.size();++i){
    // 	for(int j=i+1;j<s.size();++j){
    // 		if(s[i]==s[j]){
    // 			flag=0;
    // 			break;
    // 		}
    // 	}
    // }
    // cout<<((flag)?"yes":"no");



    string s;
    cin>>s;
    set<char>c;
    for(char k:s) c.insert(k);
    cout<<((s.size()==c.size())?"yes":"no");
    return 0;
}

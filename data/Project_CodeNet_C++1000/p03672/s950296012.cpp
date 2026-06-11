#include<bits/stdc++.h>
using namespace std;
bool fun(string sub){
	if(sub.length()&1) return false;
	else{
		int half=sub.length()/2;
		for(int i=0;i<half;++i){
			if(sub[i]!=sub[half+i]) return false;
		}
	}
	//cout<<sub<<'\n';
	return true;
}
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    int len=s.length();
    int i=1,ans=0;
    while(!(fun(s.substr(0,len-i)))) ++i;
    //fun("akasakaakasaka");
    //string temp="hello";
    //cout<<temp.substr(2,3)<<'\n';
    cout<<len-i;
    return 0;
}
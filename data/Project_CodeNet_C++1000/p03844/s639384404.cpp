#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll  unsigned long long

signed main(){
	IOS;
    #ifndef ONLINE_JUDGE 
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif

    long long int a,b;
    string s;
    cin>>a>>s>>b;
    if(s[0]=='+'){
    	cout<<a+b;
    }
    else{
    	cout<<a-b;
    }
    return 0;
}
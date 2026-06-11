#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    char c;
    int ans=0,mx=0;
    while(cin>>c){
    	(c=='I')?++ans:--ans;
    	if(ans>mx) mx=ans;
    }
    cout<<mx;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    cout<<((s[0]==s[2])?"Yes":"No");
    return 0;
}
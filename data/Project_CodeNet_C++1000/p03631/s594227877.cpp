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
    string t=s;
    reverse(t.begin(),t.end());
    cout<<((s==t)?"Yes":"No");
    return 0;
}
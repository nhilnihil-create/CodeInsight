#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*b==c*d) cout<<a*b;
    else cout<<((a*b>c*d)?a*b:c*d);
    return 0;
}
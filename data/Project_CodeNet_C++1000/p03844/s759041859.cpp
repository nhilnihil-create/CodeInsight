#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int a,b;
    char c;
    cin>>a>>c>>b;
    cout<<((c=='+')?a+b:a-b);
    return 0;
}
#include<bits/stdc++.h>
//#include<iostream>
//#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void init();
void work();

int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    ll x,y;
    cin>>x>>y;
    ll t=x>y?x-y:y-x;
    if(t<=1) cout<<"Brown";
    else cout<<"Alice";
}

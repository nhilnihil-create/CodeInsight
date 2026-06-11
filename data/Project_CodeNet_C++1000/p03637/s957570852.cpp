#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000000000000001;
int main(){
    ll n;cin>>n;
    ll b[3]={0};
    rep(i,n){
        ll a;cin>>a;
        ll cnt=0;
        while(a%2==0){
         cnt++;
         a/=2;
        }
        if(cnt==0)b[0]++;
        if(cnt==1)b[1]++;
        if(cnt>=2)b[2]++;
    }
    if(b[1]==0){
        if(b[0]-1<=b[2])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    if(b[1]!=0){
        if(b[0]<=b[2])cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
}
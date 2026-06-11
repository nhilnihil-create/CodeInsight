#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define ti3 tuple<int,int,int>
ll int MOD=1e9+7;
#define N 200000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int x,y;
  cin>>x>>y;
    if(abs(x-y)<2) cout<<"Brown";
    else cout<<"Alice";
    return 0;
}
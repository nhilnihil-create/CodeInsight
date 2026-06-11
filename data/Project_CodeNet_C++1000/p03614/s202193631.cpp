#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
using namespace std;
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
int main(void){
    ll n,cnt=0;
    cin>>n;
    int p[n+1];
    rep(i,1,n+1)cin>>p[i];
    rep(i,1,n)if(p[i]==i){
        swap(p[i],p[i+1]);
        cnt++;
    }
    cnt+=(p[n]==n);
    cout<<cnt<<endl;
    return 0;
}
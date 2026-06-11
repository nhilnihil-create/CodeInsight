//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll cnt=0,up,down;
    ll s;
    ll mx;
    for(int i=0;i<n;i++){
        up=1;down=1;
        if(a[i]<=a[i+1]){
            s=i;
            while(a[s]<=a[s+1]){
                up++;
                s++;
            }
        }
        if(a[i]>=a[i+1]){
            s=i;
            while(a[s]>=a[s+1]){
                down++;
                s++;
            }
        }
        mx=max(up,down);
        cnt++;
        i+=mx-1;
    }
    cout<<cnt<<endl;
}







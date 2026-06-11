#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    int n,m;cin>>n>>m;
    vector<P> manu(m);
    vector<int> ball(n+1);
    vector<bool> red(n+1);
    for(int i=0;i<m;i++){
        cin>>manu[i].first>>manu[i].second;
    }
    rep(i,n+1){
        ball[i]=1;
        red[i]=false;
    }
    red[1]=true;
    rep(i,m){
        ball[manu[i].first]--;
        ball[manu[i].second]++;
        if(red[manu[i].first]==true){
            red[manu[i].second]=true;
        }
        if(ball[manu[i].first]==0){
            red[manu[i].first]=false;
        }
    }
    int ans=0;
    rep(i,n+1){
        if(red[i]==true) ans++;
    }
    cout<<ans<<endl;
}
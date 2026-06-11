#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;
bool isNum(ll x){
    bool nana=false, go=false, san=false;
    while(x>0){
        int num=x%10;
        x/=10;
        if(num==3) san=true;
        if(num==5) go=true;
        if(num==7) nana=true;
    }
    return san&&go&&nana;
}

int main(){
    fast_io

    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) {
        cin>>a[i];
        a[i]--;
    }
    int ans=0;
    rep(i,n){
        if(i==a[a[i]] && i!=a[i])ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    vector<pair<ll,bool>> box(n);
    for (ll i = 0; i < n; i++){
        box[i].first = 1;
        box[i].second = false;
    }
    box[0].second = true;

    rep(i,m){
        ll x,y;
        cin >> x >> y;
        x--; y--;

        if (box[x].first == 1){
            if (box[x].second){
                box[x].second = false;
                box[y].second = true;
            }
        }
        else{
            if (box[x].second){
                box[y].second = true;
            }
        }
        box[x].first--;
        box[y].first++;
    }

    ll ans = 0;
    rep(i,n){
        if (box[i].second){
            ans++;
        }
    }

    cout << ans << endl;

}
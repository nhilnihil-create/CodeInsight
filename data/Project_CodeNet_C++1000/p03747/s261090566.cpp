#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
long double eps = 1e-9;
long double pi = acos(-1);


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,l,t;
    cin>>n>>l>>t;
    l *= 2;
    t *= 2;
    ll x[n],w[n];
    for(ll i=0;i<n;i++){
        cin>>x[i]>>w[i];
        w[i]--;
        x[i] *= 2;
    }
    ll cnt = 0;
    for(ll i=1;i<n;i++){
        if(w[0]!=w[i]){
            ll dif = x[i]-x[0];
            if(w[0]==1) dif = l-dif;
            ll tmp = t;
            if(tmp >= dif/2){
                tmp -= dif/2;
                cnt++;
            }
            cnt += tmp/(l/2);
            cnt %= n;
        }
    }
    for(ll i=0;i<n;i++){
        if(w[i]==0) x[i] = (x[i]+t)%l;
        else x[i] = (x[i]+l-(t%l))%l;
    }
    ll now = x[0];
    sort(x,x+n);
    if(w[0]==1)for(ll i=0;i<n;i++){
        if(x[i] == now){
            for(ll j=0;j<n;j++){
                cout << x[(i+j+cnt)%n]/2 << "\n";
            }
            return 0;
        }
    }
    else for(int i=n-1;i>=0;i--){
        if(x[i] == now){
            for(int j=0;j<n;j++){
                cout << x[(i+j+n-cnt)%n]/2 << "\n";
            }
            return 0;
        }
    }
}
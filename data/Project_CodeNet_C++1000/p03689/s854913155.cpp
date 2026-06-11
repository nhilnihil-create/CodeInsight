#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
	//while(true){
	ll W,H,w,h;
	cin>>H>>W>>h>>w;
    vector<vi> a(H,vi(W));
    ll sum = 0;
    rep(i,0,H)
        rep(j,0,W){
            if((i+1)%h==0&&(j+1)%w==0) a[i][j] = -1000*h*w+999;
            else a[i][j] = 1000;
            sum+=a[i][j];
        }
    if(sum>0){
        cout<<"Yes"<<endl;
        rep(i,0,H){
            rep(j,0,W) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }else cout<<"No"<<endl;//}
}

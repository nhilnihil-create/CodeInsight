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

    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    ll x = tx - sx;
    ll y = ty - sy;

    rep(i,x){
        cout << "R";
    }
    rep(i,y){
        cout << "U";
    }
    rep(i,x){
        cout << "L";
    }
    rep(i,y){
        cout << "D";
    }
    cout << "D";
    rep(i,x+1){
        cout << "R";
    }
    rep(i,y+1){
        cout << "U";
    }
    cout << "LU";
    rep(i,x+1){
        cout << "L";
    }
    rep(i,y+1){
        cout << "D";
    }
    cout << "R" << endl;

}
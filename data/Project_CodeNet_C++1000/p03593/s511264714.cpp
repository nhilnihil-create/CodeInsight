#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"Yes"<<endl
#define cno cout<<"No"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;

int main(){

    int h,w; cin >> h >> w;
    int H,W;
    H = h/2; W = w/2;
    map<char,int> mp;
    for(char c = 'a'; c <= 'z'; c++){
        mp[c] = 0;
    }
    for(char c = 'A'; c <= 'Z'; c++){
        mp[c] = 0;
    }
    rep(i,h)rep(j,w){
        char c; cin >> c;
        ++mp.at(c);
    }
    bool ok = true;
    if(h%2 == 0 && w%2 == 0){
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.at(c)%4 != 0) ok = false;
        }
        for(char c = 'A'; c <= 'Z'; c++){
            if(mp.at(c)%4 != 0) ok = false;
        }
        ok? cyes : cno;
    }
    else if(h%2 == 1 && w%2 == 1){
        int cnt_odd = 0;
        int cnt_four = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.at(c)%2 == 1) ++cnt_odd;
            cnt_four += mp.at(c)/4;
        }
        for(char c = 'A'; c <= 'Z'; c++){
            if(mp.at(c)%2 == 1) ++cnt_odd;
            cnt_four += mp.at(c)/4;
        }
        if(cnt_odd > 1) ok = false;
        if(cnt_four < H*W) ok = false;

        ok? cyes : cno;
    }
    else{
        int cnt_odd = 0;
        int cnt_four = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.at(c)%2 == 1) ++cnt_odd;
            cnt_four += mp.at(c)/4;
        }
        for(char c = 'A'; c <= 'Z'; c++){
            if(mp.at(c)%2 == 1) ++cnt_odd;
            cnt_four += mp.at(c)/4;
        }
        if(cnt_odd > 0) ok = false;
        if(cnt_four < H*W) ok = false;

        ok? cyes : cno;
    }
    return 0;
}

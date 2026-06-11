#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int i=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

bool solve(int mx, map<int, int> &mp){
    if(mx%2){
        if(mp[(mx+1)/2]!=2) return false;
        for(int x=0; x<(mx+1)/2; x++)
            if(mp[x]>0) return false;
        for(int x=(mx+1)/2+1; x<=mx; x++)
            if(mp[x]<2) return false;
        return true;
    }else{
        if(mp[mx/2]!=1) return false;
        for(int x=0; x<x/2; x++)
            if(mp[x]>0) return false;
        for(int x=mx/2+1; x<=mx; x++)
            if(mp[x]<2) return false;
        return true;
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    int mx = *max_element(a.begin(), a.end());
    map<int, int> mp;
    REP(i, N) mp[a[i]]++;
    cout << (solve(mx, mp) ? "Possible" : "Impossible") << endl;
    return 0;
}
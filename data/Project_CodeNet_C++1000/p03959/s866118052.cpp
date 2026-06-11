#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#define ll long long
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> T(N+2,0), A(N+2,0);
    for(int i=1; i<=N; i++) cin >> T[i];
    for(int i=1; i<=N; i++) cin >> A[i];
    vector<pair<int,int>> rangeT(N+1,{0,0}), rangeA(N+1,{0,0}); // {min, max}
    for(int i=1; i<=N; i++){
        rangeT[i].first = (T[i] > T[i-1] ? T[i]:1);
        rangeT[i].second = T[i];
    }
    for(int i=N; i>=1; i--){
        rangeA[i].first = (A[i] > A[i+1] ? A[i]:1);
        rangeA[i].second = A[i];
    }

    ll mod = 1e9+7;
    ll ans = 1;
    for(int i=1; i<=N; i++){
        ll minT = rangeT[i].first;
        ll maxT = rangeT[i].second;
        ll minA = rangeA[i].first;
        ll maxA = rangeA[i].second;
        if(maxT < minA || maxA < minT){
            cout << 0 << endl;
            return 0;
        }

        ll val[4] = {minT, maxT, minA, maxA};
        sort(val, val+4);
        ans = ans*(val[2]-val[1]+1)%mod;
    }
    cout << ans << endl;
}

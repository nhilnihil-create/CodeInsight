#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

ll M = 1000000007;

int main(){
    string S; cin >> S;
    ll n = S.size();
    ll K; cin >> K;
    vll a(n);
    for(int i=0; i<n; i++){
        a[i] = 'z' - S[i] + 1;
    }
    for(int p=0; p<n; p++){
        if(S[p] == 'a'){
            continue;
        }else if(K >= a[p]){
            S[p] = 'a';
            K -= a[p];
        }else{
            continue;
        }
    }
    if(K > 0){
        ll h = (K%26);
        if('z' - (S[n-1] + h) >= 0){
            S[n-1] = (S[n-1] + h);
        }else{
            S[n-1] = ('a' + ((S[n-1] + h - 'z' - 1)));
        }
    }
    cout << S;
}
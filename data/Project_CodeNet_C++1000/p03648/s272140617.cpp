#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vc = vector<char>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

ll mod = 1000000007;

int main(){
    ll K; cin >> K;
    ll m = K % 50;
    ll n = K/50;
    ll p = 49 + n;
    p -= m;
    cout << 50 << endl;
    for(int i=0; i<50; i++){
        if(i < 50-m){
            cout << p << " ";
        }
        else{
            cout << p + 51 << " ";
        }
    }
}
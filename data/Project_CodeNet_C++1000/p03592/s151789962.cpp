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

int main(){
    ll N, M , K; cin >> N >> M >> K;
    bool t = true;
    for(int i=0; i<=N; i++){
        if(t){
        for(int j=0; j<=M; j++){
            if(M*i + N*j - 2*i*j == K){
                cout << "Yes";
                t = false;
                break;
            }
        }
        }
    }
    if(t){
        cout << "No";
    }
}
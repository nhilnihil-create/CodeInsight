#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#define sz(x) ((ll)(x).size());
#define pb push_back;
#define all(x) (x).begin(),(x).end()
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vll asum(N);
    ll a = 0;
    for(int i=0; i<N; i++){
        a += A[i];
        asum[i] = a;
    }
    ll c = 1;
    for(int i=N-1; i>0; i--){
        if(A[i] <= 2*asum[i-1]){
            c++;
        }else{
            break;
        }
    }
    cout << c;
}
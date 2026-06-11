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

ll ncn(ll n){
    if(n == 1){return 2;}
    return ncn(n-1)*3*n;
}

int main(){
    ll N,P; cin >> N >> P;
    vll a(N);
    vll even(0), odd(0);
    for(int i=0; i<N; i++){
        cin >> a[i];
        if(a[i]%2==0){even.emplace_back(a[i]);}
        else{odd.emplace_back(a[i]);}
    }
    ll A = even.size(), B = odd.size();
    if(B==0&&P%2==1){
        cout << 0;
    }else if(B==0&&P%2==0){
        ll ans = 2;
        for(int i=1; i<N; i++){
            ans *= 2;
        }
        cout << ans;
    }
    else{
        ll ans = 2;
        for(int i=1; i<N-1; i++){
            ans *= 2;
        }
        cout << ans;
    }
}
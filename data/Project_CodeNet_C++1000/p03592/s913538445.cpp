#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N ,M, K;
    cin >> N >> M >> K;
    ll diff = N * M - K;
    bool flag = false;

    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= N; j++){
            if(i * (N - j) + (M - i) * j == K){
                flag = true;
            }
        }
    }
    
    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;

}

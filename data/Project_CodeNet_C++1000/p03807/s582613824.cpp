#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
//pow(x,n)
//cout << fixed << setprecision(桁数);

int main() {
    int n;
    cin >> n;

    int even = 0;
    int odd = 0;

    vector<int> vec(n);
    rep(i,n){
        cin >> vec.at(i);
        vec.at(i)%2 == 0 ? ++even : ++odd;
    }
    //cout << even << odd << endl;

    //cout << odd << endl;
    if(odd%2==0) cout << "YES";
    else cout << "NO" << endl;
}

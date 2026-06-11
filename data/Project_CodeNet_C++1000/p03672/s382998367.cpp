#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

ll cal(ll k){
    ll sum = 0;
    for (ll i = 1; i <= k; ++i)
    {
        sum += i;
    }
    if(k <= 0) return 0;
    else return sum;
}

int main() {

    string s; cin >> s;
    int n = s.length();
    int c = 2;
    int mid = 0;


    while(1){
        mid = (n-c)/2;

        if(s.substr(0,mid) == s.substr(mid,mid)){
            break;
        }
        c += 2;
    }

    cout << n-c;


    return 0;
}










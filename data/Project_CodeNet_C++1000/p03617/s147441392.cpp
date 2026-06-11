#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

//yakusuu rekkyo
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // push its partner
            if (N/i != i) res.push_back(N/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // exponential

        // divide as much as you can
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // push the result
        res.push_back({a, ex});
    }

    // last num (if the lasting n is prime number and not 1)
    if (N != 1) res.push_back({N, 1});
    return res;
}



int main() {
    double q,h,s,d,n;
    ll ans = 0;
    vector<pair<double,double>> v;

    cin >> q >> h >> s >> d >> n;
    v.push_back(make_pair(q*8,0.25));
    v.push_back(make_pair(h*4,0.5));
    v.push_back(make_pair(s*2,1));
    v.push_back(make_pair(d,2));
    sort(v.begin(),v.end());

    rep(i,v.size()){
        pair<double,double> tmp;
        tmp = v[i];
        ll t = (ll)(n/tmp.second);
        n -= t*tmp.second;
        ans += ((int)((tmp.first/(2/tmp.second)))*t);
    }
    cout << ans;


    return 0;
}










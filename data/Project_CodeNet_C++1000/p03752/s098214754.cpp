#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector <int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)

unsigned int comb(unsigned int n, unsigned int r) {
    if ( r * 2 > n ) r = n - r;
    unsigned int dividend = 1;
    unsigned int divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

int recursive_comb(int *indexes, int s, int rest, vector<vector<int>> *comb_list, int idx, int k) {
    if (rest == 0) {
        REP(i, k) {
            (*comb_list)[idx][i] = indexes[i];
        }
        idx++;
    } else {
        if (s < 0) return idx;
        idx = recursive_comb(indexes, s - 1, rest, comb_list, idx, k);
        indexes[rest - 1] = s;
        idx = recursive_comb(indexes, s - 1, rest - 1, comb_list, idx, k);
    }
    return idx;
}

// nCkの組み合わせに対して処理を実行する
ll foreach_comb(int n, int k, vector<vector<int>> *comb_list) {
    int indexes[k];
    ll len = comb(n,k);
    (*comb_list).resize(len);
    REP(i, len){
        (*comb_list)[i].resize(k);
    }
    ll idx = 0;
    recursive_comb(indexes, n - 1, k, comb_list, idx, k);
    return len;
}

int main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n,k; cin >> n >> k;
    ll a[n];
    REP(i, n) {
        cin >> a[i];
    }
    int idx = 0;
    k--;
    while (k > 0 && a[idx] < a[idx+1]) {
        idx++;
        k--;
    }
    ll smallest[n];
    smallest[0] = 0;
    FOR(i, 1, n) {
        smallest[i] = max(smallest[i-1], a[i-1]);
    }

    vector<vector<int>> comb_list;
    // nCk を全列挙
    ll len = foreach_comb(n-idx-1, k, &comb_list);
    ll mm = -1;
    REP(i, len) {
        ll s = smallest[idx];
        ll cost = 0;
        REP(j, k) {
            int ii = comb_list[i][j]+idx+1;
            s = max(s, smallest[ii])+1;
            if (a[ii] < s) cost += s-a[ii];
        }
        if (cost < mm || mm < 0) mm = cost;
    }
    cout << mm << "\n";
}
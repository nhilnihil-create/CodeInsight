// AGC017-A Biscuits

#include <bits/stdc++.h>
using namespace std;

void nCr(int n, long long ncr[]);

signed main() {
    int n, p, a, odd, even;
    long long sum_even, nco[51], nce[51], ans;

    cin >> n >> p;
    odd = 0;
    even = 0;

    for(int i=0 ;i<n ;i++ ) {
        cin >> a;

        if(a%2 == 1) {
            odd++;
        } else {
            even++;
        }
    }

    nCr(odd, nco);
    nCr(even, nce);

    sum_even = 0;
    for(int i=0 ;i<=even ; i++ ) {
        sum_even += nce[i];
    }

    ans = 0;
    if(p == 0) {
        for(int i=0 ;i<=odd ;i+=2 ) {
            ans += sum_even * nco[i];
        }
    } else {
        for(int i=1 ;i<=odd ;i+=2 ) {
            ans += sum_even * nco[i];
        }
    }

    cout << ans << '\n';
    return (0);
}

// [引数]
//          int n           : 選べる最大個数
//          long long ncr[] : 組み合わせを格納する配列
// [機能]
//          nC0 ~ nCnまでを求める
void nCr(int n, long long ncr[]) {
    ncr[0] = 1;
    int r = 1, N = n;

    for(int i=1 ;i<=N ;i++ ) {
        ncr[i] = ncr[i-1] * n / r;

        n--;
        r++;
    }

    return ;
}

/*
全員でn人の人間がいる.
自分の左右に並んでいる人数の差の絶対値がAiである
= 中央値から何人分ずれているか(左右に)
数列Aには同じ値は２回までしか登場できない.
(0の場合はnが奇数なら1回のみ,
nが偶数なら１回も存在できない.0は真ん中を表すから)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);

ll mpow(ll a, ll n, ll mod) {
    ll res = 1;
    while(n > 0){
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n;
    sc(n)
    int A[n], cnt[n];
    fill(cnt, cnt + n, 0);
    REP(i, n) sc(A[i])
    REP(i, n) cnt[A[i]] += 1;
    if ((n % 2 == 0 && cnt[0] > 0)\
     || (n % 2 == 1 && cnt[0] > 1)){
        cout << 0 << endl;
    }else{
        bool check = true;
        for (int i = 1; i < n; i++){
            if (i == 0 && cnt[i] > 2) check = false;
            else if (cnt[i] != 2 && cnt[i] != 0) check = false;
        }
        if (check) cout << mpow(2, n / 2, 1e9 + 7) << endl;
        else cout << 0 << endl;
    }
    return 0;
}
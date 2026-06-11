#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);
    int a[100000];
    rep(i, n) cin >> a[i];

    vector<int> v; //可変長配列
    map<int, int> cnt; //出現数調べるときによく使うやつ
    rep(i, n) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) cnt[a[i]] = 0, v.push_back(a[i]); //同じ長さが2本あったら、また2本来たときにカウントできるように初期化してから、v配列に追加
    }
    sort(v.begin(), v.end(), greater<int>()); //大きい順に並び替え

    ll ans = 0;
    if (2 <= v.size()) ans = 1LL * v[0] * v[1]; //同じ長さの棒が2組以上あったら、大きいものから順に乗算してlong longにキャストする。
    printf("%lld\n", ans);
}
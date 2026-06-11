#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//







int main(void) {
    
    int N; cin >> N;
    int a[N]; rep(i,N) cin >> a[i];

    int c[9]; rep(i,9) c[i] = 0;
    rep(i,N) {
        if (a[i] < 400) ++c[0];
        else if (a[i] < 800) ++c[1];
        else if (a[i] < 1200) ++c[2];
        else if (a[i] < 1600) ++c[3];
        else if (a[i] < 2000) ++c[4];
        else if (a[i] < 2400) ++c[5];
        else if (a[i] < 2800) ++c[6];
        else if (a[i] < 3200) ++c[7];
        else ++c[8];
    }

    int mn, mx;
    int kind = 0;
    rep(i,8) {
        if (c[i] > 0) ++kind;
    }
    if (kind == 0) {
        mn = 1;
        mx = c[8];
    }
    else {
        mn = kind;
        mx = kind + c[8];
    }
    cout << mn << " " << mx << endl;
    
    return 0;
}








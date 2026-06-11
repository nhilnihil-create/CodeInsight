#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    int N,K;
    cin >> N >> K;
    int l[N];
    REP(i,N) cin >> l[i];

    sort(l,l+N);
    //REP(i,N)cout << l[i] << endl;
    int ans = 0;
    REP(i,K){
        ans += l[N-i-1];
    }
    fin(ans);
    return 0;
}
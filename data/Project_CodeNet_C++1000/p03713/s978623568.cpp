#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define DEBUG 0
#define REP(i, n) for (int i = 0; i < (n); i++) 
typedef long long ll;
typedef pair<int,int> pint;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main() { 
    ll h,w;
    cin >> h >> w;
    ll hw = h * w;

    ll w2 = w / 2;
    ll h2 = h / 2;

    //それぞれの面積
    ll a,b,c;
    ll smax,smin;

    ll res = INF;

    //方針: 基本的に全探索 smaxが半分を超えたら終了
    //パターンわけ 4(not 6)パターンあるのでそれを全部調べる

    //1. 横で切る
    for(ll i = 1; i <= h-2; ++i)
    {
        a = w * i;
        //残りを半分で割るほうが良い
        ll zan = h - i;
        ll zan2 = zan / 2;
        b = w * zan2;
        c = w * (zan - zan2);

        smax = max(a,max(b,c));
        smin = min(a,min(b,c));
        res = min(res, smax - smin);
        
    }
    //2.縦できる
    for(ll i = 1; i <= w-2; ++i)
    {
        a = h * i;
        //残りを半分で割るほうが良い
        ll zan = w - i;
        ll zan2 = zan / 2;
        b = h * zan2;
        c = h * (zan - zan2);
        smax = max(a,max(b,c));
        smin = min(a,min(b,c));
        res = min(res, smax - smin);
    }
    //3. 上は1分割 下を縦に2分割
    for(ll i = 1; i <= h-1; ++i)
    {
        a = w * i;
        //残りを半分にする
        
        b = (h-i) * w2;
        c = (h-i) * (w - w2);
        smax = max(a,max(b,c));
        smin = min(a,min(b,c));
        res = min(res, smax - smin);
    }
    //4. 左は1分割 右を横に2分割
    for(ll i = 1; i <= w-1; ++i)
    {
        a = h * i;
        //残りを半分にする
        
        b = (w-i) * h2;
        c = (w-i) * (h - h2);
        smax = max(a,max(b,c));
        smin = min(a,min(b,c));
        res = min(res, smax - smin);
    }

    cout << res << endl;

    return 0;

}
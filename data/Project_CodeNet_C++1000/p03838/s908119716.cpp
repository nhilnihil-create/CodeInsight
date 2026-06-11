#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    LL x, y;
    cin >> x >> y;

    LL absDiff = abs(abs(y) - abs(x));

    LL ans = absDiff;
    if(x + absDiff == y){}
    else if(-x + absDiff == y){ans++;}
    else if(-x - absDiff == y){ans++;}
    else if(x - absDiff == y){ans+=2;}
    
    
    cout << ans << endl;
    return 0;
}
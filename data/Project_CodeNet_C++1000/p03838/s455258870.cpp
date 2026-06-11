#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int x,y;
    cin >> x >> y;
    int ans = 0;
    if( 0 <= x && 0 <= y){
        if(x <= y){
            ans += abs(y-x);
        }else{
            ans +=min(abs(-x-y)+1,abs(y-x)+2);
        }
    }else if (0 <= x && y < 0){
        ans += abs(-x - y);
        ans += 1;
    }else if (x < 0 && 0 <= y){
        ans += min(y-x,abs(-x - y)+1);
    }else{
        if(x <= y){
            ans += abs(y - x);
        }else{
            ans += abs(y - x);
            ans += 2;
        }
    }
    cout << ans << endl;
}
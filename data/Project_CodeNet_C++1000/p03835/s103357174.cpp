#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    int k, s ;
    int ans = 0 ;
    cin >> k >> s ;
    rep(i, k + 1){
        rep(j, k + 1){
            int t = s - (i + j) ;
            if(t > k || t < 0) continue ;
            ans++ ;
        }
    }
    cout << ans << endl ;
}


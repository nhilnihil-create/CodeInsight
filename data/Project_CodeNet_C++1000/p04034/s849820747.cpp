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

int main(){
    int n, m ;
    cin >> n >> m ;
    vector<int> num (n, 1) ;
    vector<bool> cn (n, false) ;
    cn[0] = true ; 
    int ans = 0 ;
    rep(i, m){
        int x, y ;
        cin >> x >> y ; 
        x-- ; 
        y-- ; 
        if(num[x] == 1 && cn[x]){
            cn[x] = false ; 
            num[x]-- ; 
            cn[y] = true ;
            num[y]++ ; 
            continue ; 
        }
        if(!cn[x]){
            num[x]-- ;
            num[y]++ ;
            continue ; 
        }
        if(num[x] > 1 && cn[x]){
            cn[y] = true ;
            num[x]-- ;
            num[y]++ ;
            continue ; 
        }
    }
    rep(i, n){
        if(cn[i]) {
            ans++ ; 
        }
    }
    cout << ans << endl ; 
}

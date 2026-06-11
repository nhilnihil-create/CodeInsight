#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
#define int long long

main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,x; cin >> n >> x;
    int a[2001]; forr(i,0,n) cin >> a[i];

    int cost = LLONG_MAX;
    int mincost[2000][2000];

    forr(i,0,n) {
        mincost[i][0] = a[i];
        forr(off,1,n) {
            mincost[i][off] = min(mincost[i][off-1], a[(i+off)%n]);
        }
    }    

    forr(off,0,n) {
        int sum = 0;
        forr(i,0,n) sum += mincost[i][off];
        cost = min(cost,sum+off*x);
    }
    cout << cost << '\n';


        
}
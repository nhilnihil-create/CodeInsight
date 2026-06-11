#include <bits/stdc++.h>
using namespace std;

//#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main(){
    int n; cin >> n;
    vector<int> a(n);
    int two[] = {0,0,0};
    rep(i,n){
        int a; cin >> a;
        if(a % 2 == 1){
            two[0]++;
        }else{
            a /= 2;
            two[!(a % 2)+1]++;
        }
    }
    
    if(two[0] == 0){
        cout << "Yes" << endl;
    }else{
        int bad_adjacent = two[0]-1 + !!two[1];
        cout << (bad_adjacent > two[2] ? "No" : "Yes") << endl;
    }
}
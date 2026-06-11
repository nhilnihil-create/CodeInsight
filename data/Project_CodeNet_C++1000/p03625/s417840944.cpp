#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
static const int MAX = 1e9 + 1;
int main(){
    int n; sc(n)
    int A[n];
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++) sc(A[i]);
    for (int i = 0; i < n; i++){
        ++mp[A[i]];
    }
    ll max1 = -1, max2 = -1;
    for (auto it = mp.begin(); it != mp.end(); it++){
        if (it->second >= 4){
            if (max1 == -1) max1 = it->first;
            max2 = it->first;
            break;
        }
        if (it->second >= 2){
            if (max1 == -1) max1 = it->first;
            else {
                max2 = it->first;
                break;
            }
        }
    }
    if (max1 == -1 || max2 == -1) cout << 0 << endl;
    else cout << max1 * max2 << endl;
    return 0;
}
#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    int k = 1;
    while(k*(k+1)/2 < n) ++k;
    vector<int> v;
    rep(i, 30)if(((k*(k+1)/2-n) >> i) & 1) v.push_back(1<<i);
    int cur = 0;
    For(i, 1, k+1){
        if(cur < v.size() && i == v[cur]){
            ++cur;
            continue;
        }
        printf("%d\n", i);
    }
}
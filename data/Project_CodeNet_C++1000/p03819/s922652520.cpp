#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;

static const int MAX_SIZE = 1 << 20; 

LL segMax[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

//区間[a, b)に値xを加算する.
void add(int a, int b, LL x, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return;

    if (a <= l && r <= b){
        segAdd[k] += x;
        return;
    }

    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);

    segMax[k] = max(segMax[k * 2 + 1] + segAdd[k * 2 + 1], segMax[k * 2 + 2] + segAdd[k * 2 + 2]);
}

LL getMax(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
    if (r <= a || b <= l) return 0;

    if (a <= l && r <= b) return (segMax[k] + segAdd[k]);

    LL left = getMax(a, b, k * 2 + 1, l, (l + r) / 2);
    LL right = getMax(a, b, k * 2 + 2, (l + r) / 2, r);

    return (max(left, right) + segAdd[k]);
}


int main(){
    int n,m;cin >> n >> m;
    vector<pair<int,pair<int,int>>> v(n);
    for (int i = 0; i < n; i++) {
        int l,r;cin >> l >> r;
        v[i] = make_pair(r - l + 1, make_pair(l, r));
    }
    sort(ALL(v));
    int k = 0;
    for (int i = 1; i <= m; i++) {
        while(k < n && v[k].first < i){
            add(v[k].second.first, v[k].second.second + 1, 1);
            k++;
        }
        int ans = n - k;
        for (int j = 1; i * j <= m; j++) {
            ans += getMax(i * j, i * j + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

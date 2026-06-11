#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}

const int MAX_N = 300005;
int bit[MAX_N+1];
int nn = MAX_N; //　1-index

void adds(int a, int w){
    for(int x = a; x <= nn; x += x & -x) bit[x] += w;
}
int sums(int a){ // bit[1,a]の和を返す.
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];  
    return ret;
}

queue<int> que[MAX_N];

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> v;
    rep(i,n){
        int l,r;
        cin >> l >> r;
        v.push_back(P(l,r));
    }
    sort(v.begin(), v.end());

    int ans[m+1] = {};
    int now = 0;
    srep(i,1,m+1){
        while(now < n && v[now].first == i){
            adds(i, 1);
            adds(v[now].second + 1, -1);
            now++;
        }
        ans[i] += sums(i) - sums(i+i);
        que[i+i].push(i);
        while(que[i].size() > 0){
            int x = que[i].front(); que[i].pop();
            ans[x] += sums(i) - sums(i+x);
            que[i+x].push(x);
        }
    }
    // srep(i,1,11)cout << sums(i);
    // cout << endl;
    srep(i,1,m+1)cout << ans[i] << endl;
    return 0;
}


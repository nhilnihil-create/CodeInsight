#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
using i64 = int64_t;
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector< set< int > > node(N);
    vector< int > used(N, 0);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        node[a].insert(b);
        node[b].insert(a);
    }
    list< int > ans;
    int l = 0, r = *node[0].begin();
    bool flag = true;
    ans.push_front(l);
    ans.push_back(r);
    used[l] = used[r] = 1;
    while(flag) {
        flag = false;
        for(auto x : node[ans.front()]) {
            if(!used[x]) {
                ans.push_front(x);
                flag = true;
                break;
            }
        }
        used[ans.front()] = 1;
    }
    flag = true;
    while(flag) {
        flag = false;
        for(auto x : node[ans.back()]) {
            if(!used[x]) {
                ans.push_back(x);
                flag = true;
                break;
            }
        }
        used[ans.back()] = 1;
    }
    cout << ans.size() << endl;
    int j = 0;
    for(auto x : ans) {
        cout << (j ? " " : "") << x + 1;
        j++;
    }
    return 0;
}
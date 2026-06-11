#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;


signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto& x : a)
        for(auto& y : x){
            cin >> y;
            --y;
        }

    auto f = [&](int val){
        // n:人数 m:試合数
        vector<queue<int>> que(n);
        for(int i = 0; i < n; ++i)
            for(auto& x : a[i])
                que[i].emplace(x);
        // スポーツ毎に人物を入れている
        vector<unordered_set<int>> s(m);
        unordered_set<int> deleted;
        for(int i = 0; i < n; ++i){
            s[que[i].front()].insert(i);
            que[i].pop();
        }
        while(1){
            // 条件を満たせない物があった場合、それを削除する
            // 削除するのはスポーツの方で、人物は削除しない
            int flag = -1;
            for(int i = 0; i < m; ++i){
                if(s[i].size() > val){
                    flag = i;
                    break;
                }
            }
            if(flag == -1)
                break;
            // 削除すると決めた要素に対して
            for(auto& x : s[flag]){
                while(1){
                    if(que[x].empty())
                        return false;
                    int fr = que[x].front();
                    que[x].pop();
                    if(deleted.find(fr) != deleted.end())
                        continue;
                    s[fr].insert(x);
                    break;
                }
            }
            s[flag].clear();
            deleted.insert(flag);
        }
        return true;
    };
    int st, en;
    for(st = 0, en = n; en - st > 1; (f((st + en) >> 1) ? en : st) = (st + en) >> 1);
    cout << en << endl;
}

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main()
{
    int n, MA, MB;
    cin >> n >> MA >> MB;
    vector<pair<int,int>> a(n);
    vector<int> cost(n);
    for(int i = 0; i < n; i++)cin >> a[i].first >> a[i].second >> cost[i];

    int m = n / 2;


    //半分全列挙
    vector<pair<int,int>> front(1 << m), back(1 << (n - m));
    vector<vector<int>> costfront(500, vector<int>(500, 1e8)); //{i,j}の組を作る最小値
    vector<vector<int>> costback(500,  vector<int>(500, 1e8));

    for(int bit = 0; bit < (1 << m); bit++){
        pair<int,int> cur;
        int curcost = 0;
        for(int i = 0; i < m; i++){
            if(bit & (1 << i)){
                cur.first += a[i].first;
                cur.second += a[i].second;
                curcost += cost[i];
            }
        }
        front[bit] = cur;
        costfront[cur.first][cur.second] = min(curcost, costfront[cur.first][cur.second]);
    }
    sort(front.begin(), front.end());

    int t = n - m;//半分全列挙の後側
    for(int bit = 0; bit < (1 << t); bit++){
        pair<int,int> cur;
        int curcost = 0;
        for(int i = 0; i < t; i++){
            if(bit & (1 << i)){
                cur.first += a[i + m].first;
                cur.second += a[i + m].second;
                curcost += cost[i + m];
            }
        }
        back[bit] = cur;
        costback[cur.first][cur.second] = min(curcost, costback[cur.first][cur.second]);
    }
    sort(back.begin(), back.end());


    int ans = 1000000000;

    for(int cef = 1; cef <= (n >= 20 ? 20 : 500); cef++){
        int ma = MA * cef;
        int mb = MB * cef;

        for(auto i : front){
            if(costfront[i.first][i.second] > ans)continue;
            pair<int,int> cur = {ma - i.first, mb - i.second};
            auto itr = lower_bound(back.begin(), back.end(), cur);
            if(itr == back.end())continue;
            if(*itr != cur)continue;

            ans = min(ans, costfront[i.first][i.second] + costback[cur.first][cur.second]);
        }
    }

    cout << (ans == 1000000000 ? -1 : ans) << endl;
}
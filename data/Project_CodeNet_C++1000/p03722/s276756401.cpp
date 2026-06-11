#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define INF 1e12
#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<ll, pair<int, int>>> edge(M);
    for (int i = 0; i < M; i++) {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
        edge[i].first *= -1;
        edge[i].second.first -= 1;
        edge[i].second.second -= 1;
    }
    
    vector<ll> dis(N,INF);
    dis[0] = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            ll cost = edge[j].first;
            int from = edge[j].second.first;
            int to = edge[j].second.second;
            if (dis[from] != INF && dis[to] > dis[from] + cost) {
                dis[to] = dis[from] + cost;
            }
            //cout << "cost=" << cost << endl;
        }
        /*
        for (int k = 0; k < N; k++) {
            printf("dis[%d]=%lld\n", k, dis[k]);
        }
        */
    }
    ll ans = dis[N - 1];
    vector<bool> nega(N, false);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ll cost = edge[j].first;
            int from = edge[j].second.first;
            int to = edge[j].second.second;
            if (dis[from] != INF && dis[to] > dis[from] + cost) {
                dis[to] = dis[from] + cost;
                nega[to] = true;
                //cout << "from=" << from << "to=" << to << endl;
            }

            if (nega[from])
                nega[to] = true;
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        printf("dis[%d]=%lld\n", i, dis[i]);
    }
    */
    if (!nega[N - 1])
        cout << -ans << endl;
    else
        cout << "inf" << endl;
}


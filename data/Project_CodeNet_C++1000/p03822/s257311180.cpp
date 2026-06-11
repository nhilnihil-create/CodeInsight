#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> par(N+1);
    vector<vector<int>> out(N+1, vector<int>());
    vector<int> outcnt(N+1, 0);
    
    par[1] = 0;
    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        par[i] = a;
        out[a].push_back(i);
        outcnt[a]++;
    }
    
    queue<int> b;
    vector<int> beat(N+1, 0);
    
    for (int i = 1; i <= N; i++) {
        if (out[i].empty()) {
            b.push(i);
        }
    }
    cout << endl;
    
    while (!b.empty()) {
        int now = b.front();
        b.pop();
        vector<int> cb;
        if (!out[now].empty()) {
            for (int c : out[now]) cb.push_back(beat[c]);
            sort(cb.begin(), cb.end());
            reverse(cb.begin(), cb.end());
            for (int i = 0; i < (int)cb.size(); i++) {
                beat[now] = max(beat[now], cb[i] + i + 1);
            }
        }
        outcnt[par[now]]--;
        if (outcnt[par[now]] == 0) b.push(par[now]);
    }
    
    cout << beat[1] << endl;
}
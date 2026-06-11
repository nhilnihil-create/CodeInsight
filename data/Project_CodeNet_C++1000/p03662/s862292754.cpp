#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e10;
typedef pair<int,int> P;

int N;
vector<int> graph[100010];
int fennec[100010];
int snuke[100010];

void bfsf(int s)  {
    for(int i = 0;i < N;i++) {
        fennec[i] = INF;
    }
    priority_queue<int,vector<int>,greater<int>> que;
    que.push(s);
    fennec[s] = 0;
    while(!que.empty()) {
        int p = que.top();
        que.pop();
        bool update = false;
        for(int i = 0;i < graph[p].size();i++) {
            if(fennec[p] + 1 < fennec[graph[p].at(i)]) {
                fennec[graph[p].at(i)] = fennec[p] + 1;
                que.push(graph[p].at(i));
                update = true;
            }
        }
    }
}

void bfss(int s)  {
    for(int i = 0;i < N;i++) {
        snuke[i] = INF;
    }
    priority_queue<int,vector<int>,greater<int>> que;
    que.push(s);
    snuke[s] = 0;
    while(!que.empty()) {
        int p = que.top();
        que.pop();
        bool update = false;
        for(int i = 0;i < graph[p].size();i++) {
            if(snuke[p] + 1 < snuke[graph[p].at(i)]) {
                snuke[graph[p].at(i)] = snuke[p] + 1;
                que.push(graph[p].at(i));
                update = true;
            }
        }
    }
}

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        graph[A - 1].push_back(B - 1);
        graph[B - 1].push_back(A - 1);
    }
    bfsf(0);
    bfss(N - 1);
    int F = 0;
    int S = 0;
    for (int i = 0; i < N; i++) {
        if(fennec[i] > snuke[i]) {
            S++;
        }
        else {
            F++;
        }
    }
    if(S >= F) {
        cout << "Snuke" << endl;
    }
    else {
        cout << "Fennec" << endl;
    }
}
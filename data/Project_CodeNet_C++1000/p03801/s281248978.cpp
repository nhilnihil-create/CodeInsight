#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll res[100005];
ll niz[100005];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
    }
    deque <int> q;
    for(int i=n; i>=1; i--){
        while(!q.empty() && niz[q.back()] <= niz[i]) q.pop_back();
        q.push_back(i);
    }
    q.push_back(0);
    priority_queue <int> pq;
    int cnt = 1;
    int rr = q.front();
    for(int i=n; i>rr; i--) pq.push(niz[i]);
    while(q.size() >= 2){
        int i = q.front();
        q.pop_front();
        int j = q.front();
        ll tren = niz[i];
        while(!pq.empty() && pq.top() > niz[j]){
            res[i] += (tren-pq.top())*cnt;
            cnt++;
            tren = pq.top();
            pq.pop();
        }
        res[i] += (tren-niz[j])*cnt;
        tren = niz[j];
        for(int k=i-1; k>j; k--){
            pq.push(niz[k]);
        }
        pq.push(tren);
    }
    for(int i=1; i<=n; i++){
        cout << res[i] << "\n";
    }
    return 0;
}

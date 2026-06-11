#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<pair<int64_t,int>> tp;
    priority_queue<int64_t> q;
    map<int, int64_t> ans;
    int n, m = 0;
    cin >> n;
    tp.emplace(0, -1);
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        q.push(a);
        if(i==0 || tp.top().first < a) tp.emplace(a, i+1);
    }
    while(tp.top().first > 0){
        int64_t t;
        int idx;
        tie(t, idx) = tp.top();
        tp.pop();
        int64_t cnt = m * (t - tp.top().first);
        while(!q.empty() && q.top() > tp.top().first){
            cnt += q.top() - tp.top().first;
            q.pop();
            ++m;
        }
        ans[idx] = cnt;
    }

    for(int i=1;i<=n;++i) cout << ans[i] << endl;
    
    return 0;
}
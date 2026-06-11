#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        A[i] = a-1;
        mp[a-1] = i;
        for (int j = 0; j < i-1; j++) {
            pq.push({-a, i});
        }
    }
    vector<int> ans;
    for (int i = 0; i < N*N; i++) {
        if (mp[i] > 0) {
            int t = mp[i];
            ans.push_back(t);
            for (int j = 0; j < N-t; j++) pq.push({-N*N*2, t});
        }else{
            if (pq.empty()) {
                cout << "No" << endl;
                return 0;
            }
            int t = pq.top().second;
            pq.pop();
            ans.push_back(t);
        }
    }
    for (int i = 1; i <= N; i++){
        auto it = ans.begin()+A[i];
        if (count(ans.begin(), it, i) != i-1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N*N; i++) {
        cout << ans[i];
        cout << ((i == N*N-1) ? "\n" : " ");
    }
    return 0;
}

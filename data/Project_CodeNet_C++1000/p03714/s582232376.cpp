#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    
    long long left = 0;
    priority_queue<int, vector<int>, greater<int>> left_que;
    for (int i = 0; i < n; i++) {
        cin >> x;
        left += x;
        left_que.push(x);
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long right = 0;
    priority_queue<int> right_que;
    for (int i = 0; i < n; i++){
        cin >> x;
        right += x;
        right_que.push(x);
    }

    vector<long long> ans(n + 1, 0);
    
    ans[0] += left;
    for (int i = 0; i < n; i++){
        left += a[i];
        left_que.push(a[i]);
        left -= left_que.top(); left_que.pop();
        ans[i + 1] += left;
    }

    ans[n] -= right;
    for (int i = n - 1; i >= 0; i--){
        right += a[i];
        right_que.push(a[i]);
        right -= right_que.top(); right_que.pop();
        ans[i] -= right;
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
}
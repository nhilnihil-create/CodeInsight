#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
int n;
int arr[MAX_N];
int leftt[MAX_N], rightt[MAX_N];
void solve(){
    memset(leftt, -1, sizeof(leftt));
    memset(rightt, -1, sizeof(rightt));
    int i = 0;
    stack<int> s;
    s.push(0);
    for(i = 1; i < n; i++){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while (!s.empty() && arr[s.top()] > arr[i]) {
            leftt[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    s.push(n - 1);
    for(i = n - 2; i >= 0; i--){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while (!s.empty() && arr[s.top()] > arr[i]) {
            rightt[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long sum = 0;
    for(i = 0; i < n; i++){
        int x, y;
        if(leftt[i] == -1)
            x = n;
        else
            x = leftt[i];
        y = rightt[i];
        //cout << x << " " << y << "\n";
        long long how_many = (long long)(i - y) * (x - i);
        sum += how_many * arr[i];
    }
    cout << sum << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int i = 0;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    solve();
    return 0;
}
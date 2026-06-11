#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    
    int num = 1, cnt = 0;
    rep(i, n){
        num = vec[num - 1];
        cnt++;
        if(num == 2){
            cout << cnt << endl;
            break;
        }
    }
    if(cnt == n) cout << -1 << endl;
    
}
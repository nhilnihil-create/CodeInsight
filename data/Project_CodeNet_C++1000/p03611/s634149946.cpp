#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int MAX = 1e+5;
int cnt[MAX+1];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cnt[a]++;
        if(a != 0) cnt[a-1]++;
        if(a != n) cnt[a+1]++;
    }
    int ans = 0;
    for(int i = 0; i < MAX; i++){
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}
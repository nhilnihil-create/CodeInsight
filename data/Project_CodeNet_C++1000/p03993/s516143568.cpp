#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    int n; cin >> n;
    int a[100000];
    int ans = 0;
    memset(a,0,sizeof(a));
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++){
        if(a[a[i]] == i){
            ans ++;
        }
    }
    cout << ans/2;

    return 0;
}










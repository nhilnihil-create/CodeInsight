#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int n,mx,cnt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(a[1] == a[n]){
        if(a[1] == n-1)
            cout << "Yes\n";
        else{
            if(2 * a[1] <= n)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    else{
        if(a[n] - a[1] > 1){
            cout << "No\n";
            return 0;
        }
        else{
            cnt = 0;
            mx = a[n];
            for(int i = 1;i <= n;++i){
                if(a[i] == a[1])
                    cnt++;
            }
            if(cnt < mx && 2 * (mx - cnt) <= n - cnt)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
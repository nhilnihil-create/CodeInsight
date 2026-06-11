#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 100000000;
    for(int k = -100; k < 101; k++){
        int cost = 0;
        for(int j = 0; j < n; j++){
            cost += (k-a[j])*(k-a[j]);
        }
        ans = min(ans,cost);
    }
    cout << ans << endl;
    return 0;
}
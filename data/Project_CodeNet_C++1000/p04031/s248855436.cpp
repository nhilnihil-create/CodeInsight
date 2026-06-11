#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n; 
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans =  numeric_limits<int>::max();
    ll sum;
    for(int i = -100; i <= 100; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            sum += (i-v[j])*(i-v[j]);
        }
        ans = min(sum,ans);
    } 
    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
const ll INF = 1001001001;

int main(){
    int n; cin >> n;
    vector<ll> a(n), sum(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        sum[i+1] = sum[i] + a[i];
    }
    int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        if(sum[i+1] * 2 < a[i + 1]){
            tmp = i + 1;
        }
    }
    cout << n - tmp << endl;
}

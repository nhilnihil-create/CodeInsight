#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main() {
    int n , x;
    cin>>n>>x;
    vector<int>v(n + 1);
    for(int i = 1; i <= n; ++i){
        cin>>v[i];
    }
    int req = 0;
    for(int i = 1 ; i <= n; ++i){
        int b = v[i] + v[i - 1];
        if(b > x){
            req += b - x;
            v[i] = x - v[i - 1];
        }
    }
    cout<<req<<"\n";
}

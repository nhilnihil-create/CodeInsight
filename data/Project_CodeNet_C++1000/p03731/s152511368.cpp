#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    cin >> a[i];
    int sum = 0;
    for(int i = 1; i < n; i++){
       if(a[i] - a[i - 1] <= t) 
       sum += (a[i] - a[i - 1]);
       else 
       sum += t;
    }
    sum += t;
    cout << sum << endl;
}
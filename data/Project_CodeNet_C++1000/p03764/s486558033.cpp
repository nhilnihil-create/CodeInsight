#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int inf = 1000000000+7;
    int n,m;
    cin >> n >> m;
    int x;
    int ans1=0;
    int ans2=0;
    for(int i=1;i<=n;i++){
        cin >> x;   
        ans1 = (ans1+(n - 2*i +1)*x)%inf;
    }
    for(int i=1;i<=m;i++){
        cin >> x;   
        ans2 = (ans2 +(m - 2*i +1)*x)%inf;
    }
    cout << (ans1*ans2)%inf;
    return 0;
    
}
#include<bits/stdc++.h>
using namespace std;


const int mod = 1e9 + 7;
const int N   = 1e5 + 5;

signed main(){
    int n;
    cin >> n;
    int ans = 0;
    int t = 0;
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d",&x);
        if(x == i) t++;
        else{
            ans += (t+1)/2;
            t = 0;
        }
    }
    
    cout << ans + (t+1)/2;
}
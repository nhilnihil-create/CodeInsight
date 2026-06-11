// 解説読んだ
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int N;
    ll x;
    cin >> N >> x;
    ll a[N], ans = 0, min_cost[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
        ans += a[i];
        min_cost[i] = a[i];
    }
    
    ll total_cost;
    for(int j=1;j<N;j++){   // 魔法を唱える回数をj回に固定
        for(int i=0;i<N;i++){
            if(i-j<0)
                min_cost[i] = min(a[N+(i-j)], min_cost[i]);
            else
                min_cost[i] = min(a[i-j], min_cost[i]);
        }
        total_cost = j*x;
        for(int i=0;i<N;i++){
            total_cost += min_cost[i];
        }
        ans = min(total_cost, ans);
        
    }

    cout << ans << endl;

}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,k;
    cin >> n >> k;
    vector<int> height(n);
    for(int i=0;i<n;i++) cin >> height[i];

    ll ans = 1LL<<60;
    for(int i=0;i<1<<n;i++){
        bitset<15> bit(i);
        int num1 = bit.count();
        if(num1!=k) continue;

        vector<int> border(n);
        border[0] = height[0];
        ll cost = 0;
        for(int j=1;j<n;j++){
            if(bit.test(j)){
                if(height[j]<=border[j-1]){
                    border[j] = border[j-1]+1;
                    cost += border[j] - height[j];
                }else{
                    border[j] = height[j];
                }
            }else{
                border[j] = max(border[j-1], height[j]);
            }
        }

        if(ans>cost){
            ans = cost;
            //cout << "bit: " << bit << ", cost: " << cost << endl;
        }

    }

    cout << ans << endl;
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int n, k, x, y; cin >> n >> k >> x >> y;
    int ans = 0;
    if(n < k){
        for(int i = 0; i < n; i++){
            ans += x;
        }
        cout << ans << endl;
    }else{
         for(int i = 0; i < k; i++){
            ans += x;
        }
        for(int i = k; i < n; i++){
            ans += y;
        }
        cout << ans << endl;
    }
    
}
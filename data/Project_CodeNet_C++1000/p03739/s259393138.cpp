#include <bits/stdc++.h>
#define N 1005
#define INF 0x3f3f3f3f 
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans;
 
int main(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    ll prefix[n];
    prefix[0] = arr[0];
    for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + arr[i];
    ll res = 0, cntr = 0;
    for(int i=0; i<n; i++){
        if(i%2){
            if(prefix[i] + cntr <= 0){
                res+=1-prefix[i]-cntr;
                cntr+=1-prefix[i]-cntr;
            }
        }else{
            if(prefix[i] + cntr >= 0){
                res+=prefix[i]+cntr+1;
                cntr-=prefix[i]+cntr+1;
            }
        }
    }
    ans = res;
    res = 0;
    cntr = 0;
    for(int i=0; i<n; i++){
        if(i%2 == 0){
            if(prefix[i] + cntr <= 0){
                res+=1-prefix[i]-cntr;
                cntr+=1-prefix[i]-cntr;
            }
        }else{
            if(prefix[i] + cntr >= 0){
                res+=prefix[i]+cntr+1;
                cntr-=prefix[i]+cntr+1;
            }
        }
    }
    ans = min(ans, res);
    cout << ans;
    return 0;
}

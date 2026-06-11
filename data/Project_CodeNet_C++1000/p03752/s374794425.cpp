#include<bits/stdc++.h>
using namespace std;
int main(){
    long n,k;
    cin >> n >> k;
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];

    long ans = 1L<<50;
    
    for(long bit=0;bit<(1<<n);bit++){
        int colors = 0;
        long maxx = a[0]-1;
        long cost = 0;
        
        for(int i=0;i<n;i++){
            if(bit & (1<<i)){
                colors++;
                cost += max(0L,maxx + 1 - a[i]);
                maxx = max(maxx+1, a[i]);
            }
            maxx = max(maxx,a[i]);
        }

        if(colors >= k){
            ans = min(ans,cost);
        }
    }
    cout << ans << endl;
    
}
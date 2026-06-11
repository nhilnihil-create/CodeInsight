#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    int n,k;
    cin >> n >> k;
    int a[n];
    long long int ans = 1e18;
    
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < (1 << n);i++){
        long long int sum = 0,k2 = 0;
        long long int last = 0;
        for(itn j = 0;j < n;j++){
            if(i & (1 << j)){
                if(last < a[j])last = a[j];
                else {
                    sum += (last+1 - a[j]);
                    last++;
                }
                k2++;
            } else {
                if(last < a[j]){
                    k2++;
                    last = a[j];
                }
            }
        }
        if(k2 >= k)ans = min(ans,sum);
    }
    cout << ans << endl;
}
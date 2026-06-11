#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long ans = 0;
    for(int i=0;i<n;i++){
        if(a[i] % 2 == 0){
            ans += a[i]/2;
        }else{
            ans += a[i]/2;
            if(i<n-1 && a[i+1] > 0){
                a[i+1]--;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

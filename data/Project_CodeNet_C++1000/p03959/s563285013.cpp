#include <iostream>
#define MOD 1000000007
using namespace std;
int main(void){
    int n, t[100000], a[100000], v;
    long long ans = 1;
    cin >> n;
    for(int i=0;i<n;i++)cin >> t[i];
    for(int i=0;i<n;i++)cin >> a[i];
    if(t[n-1] != a[0])ans = 0;
    v = n-2;
    for(int i=1;i<n;i++){
        v--;
        if(t[i] <= t[i-1])ans *= t[i];
        ans %= MOD;
        if(t[i] == t[n-1])break;
    }
    for(int i=n-2;i>=0;i--){
        v--;
        if(a[i] <= a[i+1])ans *= a[i];
        ans %= MOD;
        if(a[i] == a[0])break;
    }
    if(v <= -2)ans = 0;
    while(v-- > 0){
        ans *= a[0];
        ans %= MOD;
    }
    cout << ans << endl;
}

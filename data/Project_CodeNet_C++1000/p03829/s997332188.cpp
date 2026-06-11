#include<bits/stdc++.h>
using namespace std;
long long x[100001]; 
int main(){
    long long ans = 0,n,a,b;
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 2;i <= n;i++) ans += min((x[i] - x[i - 1]) * a,b); 
    cout << ans << endl;
}
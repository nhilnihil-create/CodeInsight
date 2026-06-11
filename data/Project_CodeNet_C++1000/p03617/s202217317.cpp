#include <bits/stdc++.h>
using namespace std;

int main() {
long long q,h,s,d,n;
cin >> q >> h >> s >> d >> n;
if(n==1){
    cout << min({q*4,h*2,s}) << endl;
    return 0;
}
else{
long long find=min({q*8,h*4,s*2,d});
long long ans = find*(n/2);
if(!(n%2==0))ans += min({q*4,h*2,s});
cout << ans << endl;
}
}

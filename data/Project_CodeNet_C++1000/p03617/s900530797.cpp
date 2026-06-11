#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q,h,s,d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;
    long long a=min({q*8,h*4,s*2,d});
    long long b=0;
    if(a==d){
        b=1;
    }
    long long ans=0;
    if(b==1){
        if(n%2==0){
            ans+=a*(n/2);
        }
        else{
            ans+=(a*(n/2))+min({q*4,h*2,s});
        }
    }
    else{
        ans+=(a/2)*n;
    }
    cout << ans << endl;
}
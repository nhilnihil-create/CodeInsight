#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll h,w;
    cin >> h >> w;
    if(h%3==0 || w%3==0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = min(h,w);
    for(ll i=1; i<=w-1; i++){
        ll s1,s2,s3;
        s1=i*h;
        if(h%2==0){
            s2=(w-i)*h/2;
            s3=(w-i)*h/2;
        }
        else{
            s2=(w-i)*(h/2);
            s3=(w-i)*(h/2+1);
        }
        ll dif = max(s1,s3) - min(s1,s2);
        ans = min(ans, dif);
    }
    for(ll i=1; i<=h-1; i++){
        ll s1,s2,s3;
        s1=i*w;
        if(w%2==0){
            s2=(h-i)*w/2;
            s3=(h-i)*w/2;
        }
        else{
            s2=(h-i)*(w/2);
            s3=(h-i)*(w/2+1);
        }
        ll dif = max(s1,s3) - min(s1,s2);
        ans = min(ans, dif);
    }
    cout << ans << endl;
}
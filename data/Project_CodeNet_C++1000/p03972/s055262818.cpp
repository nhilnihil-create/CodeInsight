#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
  
signed main(){
    int w,h;
    cin>>w >>h;
    int a[w],b[h];
    for(int i=0;i<w;i++)cin>>a[i];
    for(int i=0;i<h;i++)cin>>b[i];
    sort(a,a+w);
    sort(b,b+h);
    int p=0,q=0,ans=0;
    while(p<w&&q<h){
        if(a[p]<b[q]){
            ans+=a[p]*(h+1-q);
            p++;
        }else{
            ans+=b[q]*(w+1-p);
            q++;
        }
    }
    while(p<w){
        ans+=a[p];
        p++;
    }
    while(q<h){
        ans+=b[q];
        q++;
    }
    cout<<ans;

    return 0;
}

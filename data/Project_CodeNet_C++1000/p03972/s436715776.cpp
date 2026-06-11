#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long w,h;
    cin>>w>>h;
    long long p[w],q[h];
    long long ans=0;
    
    for(int i=0;i<w;i++){
        cin>>p[i];
        ans+=p[i];
    }
    for(int i=0;i<h;i++){
        cin>>q[i];
        ans+=q[i];
    }

    sort(p,p+w);
    sort(q,q+h);

    

    for(int i=0;i<h;i++){
        long long cnt;
        cnt=p+w - upper_bound(p,p+w,q[i]);
        ans += cnt * q[i];
        
    }
    for(int i=0;i<w;i++){
        long long cnt;
        cnt=q+h - lower_bound(q,q+h,p[i]);
        ans += cnt * p[i];
    }

    cout<<ans<<endl;
    
}

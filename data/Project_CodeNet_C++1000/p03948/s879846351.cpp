#include <iostream>
#include <algorithm>
using namespace std;
int n,t,a[100005],r,ans;
int main(void){
    cin>>n>>t;
    for(int i=0;i<n;i++)cin>>a[i];
    int m=1000000000;
    for(int i=0;i<n;i++){
        m=min(m,a[i]);
        r=max(r,a[i]-m);
    }
    m=1000000000;
    for(int i=0;i<n;i++){
        m=min(m,a[i]);
        if(a[i]-m==r)ans++;
    }
    cout<<ans<<endl;
}

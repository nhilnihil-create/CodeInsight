#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long a[7];
    for(int i=0;i<7;i++){
        cin>>a[i];
    }
    long long ans=0;
    ans+=a[1];
    int c=0;
    if(a[0]%2==1) c++;
    if(a[3]%2==1) c++;
    if(a[4]%2==1) c++;
    if(c>1 && a[0]&& a[4]&&a[3]) ans+=3,a[0]--,a[3]--,a[4]--;
    ans+=a[0]/2*2;
    ans+=a[3]/2*2 + a[4]/2*2;
    cout<<ans;
}
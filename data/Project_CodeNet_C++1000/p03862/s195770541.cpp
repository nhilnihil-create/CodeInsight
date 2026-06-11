#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long> a(n);
    long long ans=0;
    cin>>a[0];
    if(a[0]>x){
        ans+=a[0]-x;
        a[0]=a[0]-ans;
    }
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]+a[i-1]>x){
            long long tmp=a[i]+a[i-1]-x;
            ans+=tmp;
            a[i]-=tmp;
        }
    }
    cout<<ans<<endl;
    return 0;
}
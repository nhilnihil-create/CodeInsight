#include<iostream>
#include<algorithm>
using namespace std;

int check(int n,int* a){
    for(int i=0;i<n;i++){
        if(a[i]%10) return i;
    }
    return -1;
}
void solve(int n,int* a){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    if(ans%10){
        cout<<ans<<endl; return;
    }
    sort(a,a+n);
    int k=check(n,a);
    if(k!=-1){
        cout<<ans-a[k]<<endl;
        return;
    }
    cout<<0<<endl;
}
int main(){
    int a[128],n;
    while(cin>>n){
        for(int i=0;i<n;i++) cin>>a[i];
        solve(n,a);
    }
    return 0;
}

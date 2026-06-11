#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    vector <long long> a(n+1,0);
    f(i,1,n+1){
        cin>>a[i];
    }
    f(i,1,n+1){
        if(a[a[i]]==i){
            ans++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}

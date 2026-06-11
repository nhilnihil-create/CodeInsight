#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0,now=3,k=1;
    cin>>n;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
    }
    if(a[0]>a[1]){
        now=1;
    }
    else if(a[0]<a[1]){
        now=2;
    }
    f(i,2,n){
        if(a[i]>a[i-1]){
            if(now==1&&k>=1){
                ans++;
                k=0;
            }
            else{
                k++;
            }
            now=2;
        }
        else if(a[i]<a[i-1]){
            if(now==2&&k>=1){
                ans++;
                k=0;
            }
            else{
                k++;
            }
            now=1;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}

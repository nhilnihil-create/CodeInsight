#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,n,ans=0;
    cin>>n;
    map <long long,long long> b;
    f(i,0,n){
        cin>>a;
        b[a]++;
        if(b[a]%2==0){
            ans--;
        }
        else{
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define MN 111111
int N,z;
int s[MN],A[MN];
signed main(){
    cin>>N>>z;N--;
    int h=0,a;
    char c;
    rep(i,N){
        cin>>c>>a;
        s[i]=(c=='+')?1:-1;
        A[i]=a;
        h+=a*s[i];
    }

    int ans=h,l=0,m=0;
    for(int i=N-1;i>=0;i--){
        l+=A[i];
        h-=A[i]*s[i];
        if(s[i]<0){
            ans=max(ans,h-l+m);
            m+=l;
            l=0;
        }
    }
    cout<<ans+z<<endl;
    return 0;
}

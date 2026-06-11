#include <bits/stdc++.h>
using namespace std;
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scs(s) scanf("%s",s)
#ifndef GET_MACRO

#define GET_MACRO(__1,__2,__3,NAME,...) NAME

#endif // GET_MACRO

#define sci(...) GET_MACRO(__VA_ARGS__,sci3,sci2,sci1)(__VA_ARGS__)
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LSB(i) ((i)&(-i))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define infl 0x7ffffffffffffff
#define infi  0x7fffffff
#define fill_(a,b) fill(a.begin(),a.end(),b)
#define pb push_back
#define xx first
#define yy second
int main(){
    int A[100000],B[100000],i,j;
    int  n;
    sci(n);
    for(i=0;i<n;i++){
        sci(A[i],B[i]);
    }
    ll ans=0;
    ll tsum=0;
    ll tmp;
    for(i=n-1;i>=0;i--){
        ans+=(B[i]-((ll)(A[i]+ans)%(ll)B[i]))%B[i];

    }
    cout<<ans<<endl;
    return 0;
}

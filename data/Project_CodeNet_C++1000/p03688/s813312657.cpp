#include<bits/stdc++.h>
using namespace std;

#define si(n) scanf("%d",&n)
#define MAX 1000006
typedef long long ll;

ll a[MAX];

string ans(int n)
{
    if(a[n-1] -a[0] >1) return "No";
    if(a[n-1]> n-1) return "No";
    int mcnt=0,cnt=0;
    int m = a[n-1];
    for(int i=0;i<n;i++) {
        cnt+=a[i]==m-1;
        mcnt+=a[i]==m;
    }
    if((mcnt == n && m==n-1)) return "Yes";
    ll k= mcnt-n+m;
//    cout<<" k= "<<k<<"\n";
    if(k>0 && k<=m && k<= n-m ) return "Yes";
    else return "No";
}
int main()
{
    ll n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cout<<ans(n)<<"\n";
}

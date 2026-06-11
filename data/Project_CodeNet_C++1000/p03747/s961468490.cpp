#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define met(a, x) memset(a,x,sizeof(a))
#define mp make_pair;

using namespace std;
const int mod = 19e+7;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

int x[N],w[N],n,l,t;
ll c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>l>>t;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>w[i];
        if(w[i]==2)
            w[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int ans=x[i]+w[i]*t;
        if(ans>0){
            c=(c+ans/l)%n;
        }
        else if(ans<0){
            c=(c+(ans+1)/l-1)%n;
        }
        x[i]=((ans%l)+l)%l;
    }
    sort(x+1,x+1+n);
    c=(c+n)%n;
    for(int i=c+1;i<=n;i++)
        cout<<x[i]<<endl;
    for(int i=1;i<=c;i++)
        cout<<x[i]<<endl;
    return 0;
}
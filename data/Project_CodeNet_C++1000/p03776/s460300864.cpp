#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>pa;
map<int,int>mp;
const int N=2e5+100;
ll c[100][100];
ll x[100];
void init()
{
    memset(c,0,sizeof c);
    c[0][0]=1;
    for(int i=1;i<=50;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
}
int main()
{
  // ios::sync_with_stdio(0);cin.tie(0);
    int n,a,b;
    init();

    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    sort(x+1,x+1+n,greater<ll>());
    long double ave=0;
    for(int i=1;i<=a;i++)
        ave+=x[i];
    int pos1,pos2;
    for(int i=1;i<=n;i++){
        if(x[i]==x[a]) {
            pos1=i;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(x[i]==x[a]){
            pos2=i;
            break;
        }
    }
    int k=b;
    if(pos1!=1) k=a;
    k=min(k,pos2);
    ll ans=0;
    int num=pos2-pos1+1;
   // cout<<a<<" "<<k<<" "<<num<<endl;
    for(int i=a;i<=k;i++){
        ans+=c[num][i-pos1+1];
    }
    cout<<fixed<<setprecision(6);
    cout<<ave/a<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
15 8 11
981260158260522 316250877914575 547116602436426 223540024979445 408917861648772 859962623690081 509054433933447 713016476190629 845426262703497 335723211047202 842184971407775 49062628894325 324828731963982 979173822804784 312150450968417

*/

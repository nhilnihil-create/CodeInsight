
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define tam 500001
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define CLASSNAME WarmupWithTwins
#define FUNCNAME determineTwinsAge
using namespace std;

typedef long long       ll;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii> vii;
typedef long double lldb;
const ll MOD=1e9+7;
ll F[tam],F2[tam];
ll pot(ll base,ll exp)
{
    ll auxb=base%MOD,resp=1;
    while(exp>0)
    {
        if (exp&1)
            resp*=auxb,resp%=MOD;
        auxb*=auxb;
        auxb%=MOD;
        exp/=2;
    }
    return resp;
}
ll C(ll x,ll y)
{
    if (y>x)return 0;
    ll resp=F[x];
    resp*=F2[y];resp%=MOD;
    resp*=F2[x-y];resp%=MOD;
    return resp;
}
int main()
{
    F[0]=F2[0]=1;
    forr(i,1,tam)
    {
        F[i]=F[i-1]*i;F[i]%=MOD;
        F2[i]=F2[i-1]*pot(i,MOD-2);F2[i]%=MOD;
        
    }
    ios::sync_with_stdio(false);cin.tie(0);
    ll H,W;
    cin>>H>>W;
    ll A,B;
    cin>>A>>B;
    ll a2,b2,suma,formas=0;
    forr(a,A+1,H+1)
    {
        a2=H-a+1,b2=B;
        suma=C(a2-1+b2-1,a2-1);
        a2=a;b2=W-B;
        suma*=C(a2-1+b2-1,a2-1);suma%=MOD;
        formas+=suma;formas%=MOD;
    }
    /*cout<<formas<<endl;
    ll resta=C(H-A+1-1+B-1,B-1);
    cout<<resta<<" ";
    resta*=C(W-B+1-1+A-1,A-1),resta%=MOD;
    cout<<resta<<endl;
    resta%=MOD;
    formas-=resta;formas+=MOD;formas%=MOD;*/
    cout<<formas<<endl;
}
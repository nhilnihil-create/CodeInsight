#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define set0(a) memset ((a), 0 , sizeof(a))
#define set1(a) memset((a),-1,sizeof (a))
#define pi pair<int, int>
#define ps pair<string, string>
#define pl pair<long, long>
#define pll pair<long long, long long>
#define vll vector<long long>
#define vl vector<long>
#define vi vector<int>
#define vs vector<string>
#define vps vector< ps >
#define vpi vector< pi >
#define vpl vector< pl >
#define vpll vector< pll >
#define flash  ios_base::sync_with_stdio(false); cin.tie(NULL);
long long modexp(long long A,long long B,long long M){
    if(B==0)
    return 1;
    else if(B%2==0)
    return modexp((A*A)%M,B/2,M);
    else if(B%2!=0)
    return (A*modexp((A*A)%M,(B-1)/2,M))%M;

}
bool sortbysec(const pll &a,
              const pll &b)
{
    return (a.second < b.second);
}

void func(void)
{
        freopen("input.c","r",stdin);
        freopen("output.c","w",stdout);
}
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll h[n]={};
    int flag=0;
    for(ll i=0;i<n;i++){
            cin>>a[i];
            h[a[i]]++;
            if(n%2==0 && a[i]==0){
                flag=1;
                break;
            }
            if(h[0]>1){
                  flag=1;
                break;
            }
            if(h[a[i]]>2){
                 flag=1;
                break;
            }

    }
    ll ans;
    if(flag!=1){

             ans=modexp(2,n/2,mod);

    }
    else ans=0;

    cout<<ans<<endl;
}

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
#define fast1  ios_base::sync_with_stdio(false);
#define fast2 cin.tie(NULL);

bool sortbysec(const pll &a,
              const pll &b)
{
    return (a.second < b.second);
}

void func(void)
{
        freopen("input.txt","r",stdin);
        //freopen("output.c","w",stdout);
}
void sieve(bool *a,ll n){
    for(ll i=0;i<=n;i++ ){
        a[i]=true;
    }
    for(ll i=2;i*i<=n;i++){
        for(ll j=i+i;j<=n;j=j+i){
            a[j]=false;
        }
    }

}
void calculate(bool *p,ll n){
    ll answer=0;
    ll answer2=1;
    for(ll i=2;i<=n;i++){
            answer=0;
        if(p[i]){

                ll m=n;
                while(m){
                    m=m/i;
                    answer=(answer%mod+m%mod)%mod;

                }

        }
        answer2=((answer2%mod)*((answer+1)%mod))%mod;
    }
    cout<<answer2<<endl;
}
int main(){
    ll n;
    cin>>n;
    bool prime[n+1];
    sieve(prime,n);
    calculate(prime,n);
}

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
#define f first
#define s second
#define pb push_back
#define pp push
#define RETURN exit(0)
#define pow(x,y) (int)(pow(x,y))
#define ceil(x) (int)(ceil(x))
#ifndef ONLINE_JUDGE
#define debug(x) cout<<x<<endl;
#else
#define debug(x) 42
#endif
const int MAX=1e4;
const int MOD=1e9+7;
const int MAAX=1e15;
const long double EPS=1e-6;
const int N=1e6;
int power(int x,int y)
{
    if (y == 0)
        return 1;
    int a=power(x,y/2);
    if (y % 2 == 0)
        return a * a % MOD;
    else
        return x * a * a % MOD;
}
long double sq(int x){
    long double s=0,e=x,mid;
    while(e-s>=EPS){
        mid=(s+e)/2;
        if(mid*mid<=x){
            s=mid;
        }
        else{
            e=mid-EPS;
        }
    }
    return s;
}
vector<int> primes;
bool visted[N+5];
void sieve(){
    visted[0]=visted[1]=1;
    for(int i=2;i*i<=N;i++){
        if(visted[i]==0){
            primes.pb(i);
            for(int j=i*i;j<=N;j+=i){
                visted[j]=1;
            }
        }
    }
    for(int i=sqrt(N)+1;i<=N;i++){
        if(visted[i]==0)
            primes.pb(i);
    }
    return;
}



in main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int tc=1;
    //sieve();
    //scanf("%lld",&tc);
    while(tc--)
    {
        string s;
        cin>>s;
        int x=-1,y=-1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])
                x=i+1,y=i+2;
        }
        if(x==-1){
            for(int i=0;i<s.size()-2;i++){
                if(s[i]==s[i+2])
                    x=i+1,y=i+3;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
    RETURN;
}

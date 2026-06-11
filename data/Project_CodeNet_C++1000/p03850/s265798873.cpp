/// Kazuki Hoshino


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pi> vpi;
#define inf 10000000000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define endl '\n'

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

ll n , a[101010], dp[101010], sum[101010], x, pre, mn=-inf, t;
bool pm[101010];
char ch;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


    //cin >> t;

//while(t--){

    cin >> n >> x;
    dp[0]=x;

    n--;

    rep(i, 0, n-1){
        cin >> ch >> x;

        pm[i]=ch!='+';

        sum[i+1]=x;
        a[i]=x;

    }

    rep(i,1,n){
        sum[i+1]+=sum[i];
    }

    pre=-1;

    rep(i,0,n-1){

        if(pm[i] && pre!=-1){
            chmax(mn,dp[pre]-(sum[i]-sum[pre])-sum[i]);
        }
        if(!pm[i]){
            dp[i+1]=max(dp[i],mn+sum[i])+a[i];
        }
        else{
            dp[i+1]=max(dp[i]-a[i],mn+sum[i]+a[i]);
            pre=i;
        }
    }
    cout<<dp[n]<<endl;

//}


return 0;
}
///....

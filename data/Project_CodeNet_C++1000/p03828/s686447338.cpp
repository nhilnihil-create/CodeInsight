#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int prime[1010];
bool is_prime[1011];
void sieve(){
    int n = 1010; // n以下の素数を求める
    int p = 0;
    for(int i=0;i<=n;i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <=n ; i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j <=n;j*=2) is_prime[j] = false;
        }
    }
}
vector<int> num(1010,0);

int main(){
    ll n;
    cin >> n;
    if(n==1) {
        cout<<"1"<<endl;
        return 0;
    }
    sieve();
    for(int i=2;i<=n;i++){
        ll number = i;
        for(ll j=2;j<=i;j++){
            if(is_prime[j]==true){
                while(number%j==0){
                    num[j]++;
                    number/=j;
                }
            }
        }
    }
    ll ans = 1;
    //cout<<is_prime[5]<<"add"<<endl;
    //rep(i,8) cout<<num[i]<<" ";
    //cout<<endl;
    for(ll i=2;i<=n;i++){
        ans *= (num[i]+1);
        ans %= mod;
    }
    cout<< ans <<endl;
    return 0;
}
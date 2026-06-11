#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    /*左から決まらないか？
    そもそも縦に並ぶか横に重ねて並ぶかしか可能性がない
    今回の条件だと
    ...aad...
    ...cbb..
    みたいに一個ずれて重なることがあり得ない。一個のサイズがどれも2だから
    じゃあ簡単じゃないか？
     */
    int n;
    string s,t;
    cin>>n;
    cin>>s;
    cin>>t;
    ll ans;
    int i=0;
    if(s[0]==t[0]){
        ans=3;i++;
    }
    else{
        ans=3*2;i+=2;
    }
    while(i<n){
        if(s[i-1]==t[i-1]){
            if(s[i]==t[i]){
                ans=(ans*2)%mod;
                i++;
            }
            else{
                ans=(ans*2)%mod;
                i+=2;
            }
        }
        else{
            if(s[i]==t[i]){
                i++;
            }
            else{
                ans=(ans*3)%mod;
                i+=2;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
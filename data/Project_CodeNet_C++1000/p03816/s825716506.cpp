#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
map<int,int> mp;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++;
}
int sum=0,eat=0;
bool ok=true;
for(auto p:mp){
    if(p.se==1)sum++;
    else{
        if(p.se>2){
                  if((p.se-3)%2==0)sum++;
                  else eat+=2;
            }
        else eat+=2;
        if(eat>=3){
            sum+=2;
            eat=0;
        }
    }
}
//２枚ダブりが合って終わった場合、sumから１つとって操作を行う必要があるが、制約でsumが必ず１つは存在することが確約されていて\
sumから１枚取ったあと1枚プラスされるためそのような処理をしなくても良い
cout<<sum<<endl;
}
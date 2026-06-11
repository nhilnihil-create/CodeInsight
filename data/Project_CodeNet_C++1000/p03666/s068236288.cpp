#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,b,c,d,dif,now=1,M=INF,cnt=0;
    cin>>n>>a>>b>>c>>d;
    dif=d*(n-1)+a-b;
    // cout<<dif<<endl;
    if(dif<0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(c==d && c==0){
        if(a==b){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
        return 0;
    }
    if(c==d){
        if(dif%(2*d)==0){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
        return 0;
    }
    for(ll i=c+d;i<=2*d;i++){
        if(M>dif%i){
            M=dif%i;
            now=i;
        }
        if(M<(n-1-dif/now)*(d-c)+1){
            break;
        }
    }
    cnt+=dif/now;
    dif%=now;
    if(dif<=d-c){
        cnt++;
    } else{
        cnt+=dif/(d-c);
        if(dif%(d-c)!=0) cnt++;
    }
    if(cnt<n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
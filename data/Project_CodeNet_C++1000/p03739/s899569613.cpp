#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ll n;
    cin>>n;
    v a(n);
    rep(i,0,n)cin>>a[i];

    v subsum(n);
    subsum[0] = a[0];
    rep(i,1,n){
        subsum[i] = subsum[i-1]+a[i];
    }
    ll diff = 0;
    ll ans1 = 0, ans2 = 0;
    rep(i,0,n){
        if(i%2 == 0){
            if(subsum[i]+diff <= 0){
                ans1 += (1-(subsum[i]+diff));
                diff += 1-(subsum[i]+diff);
            }
        }
        else{
            if(subsum[i]+diff >= 0){
                ans1+= (1+(subsum[i]+diff));
                diff += -(1+(subsum[i]+diff));
            }
        }
    }
    diff = 0;
    rep(i,0,n){
        if(i%2 == 1){
            if(subsum[i]+diff <= 0){
                ans2+=1-(subsum[i]+diff);
                diff += 1-(subsum[i]+diff);
            }
        }
        else{
            if(subsum[i]+diff >= 0){
                ans2+=1+(subsum[i]+diff);
                diff += -(1+(subsum[i]+diff));
            }
        }
    }
    cout<<min(ans1,ans2);
    return 0;
}
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

    ll N,x;
    cin>>N>>x;
    bool ok=true,o=true;
    if(x == 1 || x == 2*N-1)o = false;
    if(N<x){
        x=2*N-x;
        ok = false;
    }
    v ans(2*N);
    ll c = 1;
    rep(i,N-(x-1),N+(x-1)+1){
        ans[i] = c;
        c++;
    }
    rep(i,1,N-(x-1)){
        ans[i] = c;
        c++;
    }
    rep(i,N+(x-1)+1,2*N){
        ans[i] = c;
        c++;
    }
    if(o){
        cout<<"Yes"<<endl;
        rep(i,1,2*N){
            if(!ok)cout<<2*N-ans[i]<<endl;
            else cout<<ans[i]<<endl;
        }
    }
    else cout<<"No"<<endl;

    return 0;
}
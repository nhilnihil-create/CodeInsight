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
    ll N;
    cin>>N;
    v A(N);
    rep(i,0,N)cin>>A[i];

    sort(all(A));
    ll sum =0;
    rep(i,1,N){
        if(A[i] == A[i-1])sum++;
    }
    if(sum%2 == 1)sum++;
    cout<<N-sum;
    return 0;
}
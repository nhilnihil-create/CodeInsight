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
    string S;
    cin>>S;
    ll ans = INF;
    rep(i,0,26){
        ll sum = 0;
        ll summax = 0;
        v temp;
        rep(j,0,S.size()){
            if(S[j] != char('a'+i))sum++;
            else{
                temp.PB(sum);
                sum = 0;
            }
            temp.PB(sum);
        }
        sort(all(temp));
        ans = min(ans, temp[temp.size()-1]);
    }
    cout<<ans;
    return 0;
}
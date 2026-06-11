#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n;
    cin >> n;
    vector<ll> data(n);
    rep(i,0,n){
        cin >> data[i];
    }
    ll ans = 1;
    bool up = false;
    bool down = false;
    ll now_num = data[0];
    rep(i,0,n){
        if(!up&&!down){
            if(now_num<data[i]){
                up = true;
                now_num = data[i];
            }else if(now_num>data[i]){
                down = true;
                now_num = data[i];
            }
        }else if(up){
            if(now_num<data[i]){
                now_num = data[i];
            }else if(now_num > data[i]){
                ans++;
                now_num = data[i];
                up = false;
            }
        }else if(down){
            if(now_num>data[i]){
                now_num = data[i];
            }else if(now_num<data[i]){
                ans++;
                now_num = data[i];
                down = false;
            }
        }
    }
    cout<<ans<<endl;
  return 0;
}
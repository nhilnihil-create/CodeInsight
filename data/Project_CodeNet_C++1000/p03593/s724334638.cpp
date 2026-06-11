#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll H,W;
unordered_map<char,ll> mp;
int main(){
    cin>>H>>W;
    for(ll i=0;i<H;i++){
        string s;
        cin>>s;
        for(auto c:s){
            mp[c]++;
        }
    }
    ll oneCnt=0;
    ll twoCnt=0;
    if(H%2==1)twoCnt+=W/2;
    if(W%2==1)twoCnt+=H/2;
    if(H%2==1 && W%2==1)oneCnt++;
    for(auto p:mp){
        ll n=p.second;
        if(n%4==2)twoCnt--;
        if(n%2==1)oneCnt--;
    }
    if(twoCnt>=0 && oneCnt >=0){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
    return 0;
}
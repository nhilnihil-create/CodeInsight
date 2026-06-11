#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll > P;
typedef pair<P,ll>Q;


int main(void){
    string s;
    cin>>s;
    ll n = s.length();
    ll ans = n*(n-1)/2;
    map<char,ll>m;
    for(int i=0;i<n;i++)m[s[i]]++;
    for(auto itr = m.begin();itr!=m.end();++itr){
        ll num = itr->second;
        ans-=num*(num-1)/2;
    }
    cout<<ans+1<<endl;
    return 0;
}
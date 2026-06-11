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
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 

 
int main(void){
    ll ans = 0;
    ll now = 0;
    ll past = 0;
    ll n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        ll ti;
        cin>>ti;
        if(ti>now){
            ans += now-past;
            past = ti;
            now = ti+t;
        }
        else{
            now = ti+t;
        }
    }
    cout<<ans+now-past<<endl;
    return 0;
}
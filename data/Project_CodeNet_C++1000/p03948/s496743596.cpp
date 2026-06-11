#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#define ll long long int
#define MOD 1000000007LL
using namespace std;

int main() {
    ll n,t;
    cin>>n>>t;
    ll a;
    ll b[114514];
    cin>>a;
    ll m=a;
    ll ma=0;
    for(int i=1;i<n;i++){
        cin>>a;
        b[i]=(t/2)*(a-m);
        m=min(m,a);
        ma=max(ma,b[i]);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(b[i]==ma){
            ans++;
        }
    }
    cout<<ans<<endl;
}

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector <ll> g[10];
ll visited[10];
int main(){
    ll n;
    cin >> n;
    ll i;
    ll a[(n+1)/2];
    for(i=0;i<(n+1)/2;i++){
        a[i]=0;
    }
    ll A;
    for(i=0;i<n;i++){
        cin >> A;
        a[A/2]+=1;
        if((A+n)%2==0){cout << 0;return 0;}
    }
    for(i=1;i<(n+1)/2;i++){
        if(a[i]!=2){cout << 0;return 0;}
    }
    if(a[0]!=1+(n+1)%2){cout << 0;return 0;}
    ll ans=1;
    for(i=0;i<n/2;i++){
        ans=ans*2%1000000007;
    }
    cout << ans;
    return 0;
}

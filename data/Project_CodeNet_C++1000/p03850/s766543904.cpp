#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
ll n,ans;
vector<P>a;
ll p[100005];
int main(void){
    cin>>n;
    ll b=1,c;
    cin>>c;
    for(int i=1;i<n;i++){
        char s;
        ll x;
        cin>>s>>x;
        if(s=='-'){
            a.PB(P(b,c));
            b=-1;
            c=x;
        }else{
            if(b==1)c+=x;
            else{
                a.PB(P(b,c));
                b=1;
                c=x;
            }
        }
    }
    a.PB(P(b,c));
    n=a.size();
    for(int i=n-1;i>=0;i--){
        p[i]+=p[i+1];
        p[i]+=a[i].S;
        ans+=a[i].F*a[i].S;
    }
    if(n==2){
        cout<<a[0].S+a[1].F*a[1].S<<endl;
        return 0;
    }
    ll r=a[0].S;
    for(int i=1;i<n-1;i+=2){
        if(a[i+1].F==1){
            ans=max(ans,r-a[i].S-a[i+1].S+p[i+2]);
            r=r-a[i].S+a[i+1].S;
        }else{
            ans=max(ans,r-a[i].S+p[i+1]);
            break;
        }
    }
    cout<<ans<<endl;
}

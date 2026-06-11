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
    ll n,L;
    cin>>n>>L;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    bool flag = true;
    int finish = 1;
    for(ll i=0;i<n-1;i++){
        if(a[i]+a[i+1]>=L){
            flag = false;
            finish = i+1;
        }
    }
    if(flag)cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        for(int i=1;i<finish;i++)cout<<i<<endl;
        for(int i=n-1;i>=finish;i--)cout<<i<<endl;
    }
    return 0;
}
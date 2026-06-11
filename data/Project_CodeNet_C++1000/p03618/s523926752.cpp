#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;



int main(void){
    string A;
    cin>>A;
    ll n=A.length();
    ll ans=n*(n-1)/2;
    map<char,ll>a;
    for(int i=0;i<n;i++){
        a[A[i]]++;
    }
    ll num=0;
    for(char x='a';x<='z';++x){
        if(a[x]==0)continue;
        else{
            num+=a[x]*(a[x]-1)/2;
        }
    }
    cout<<ans-num+1<<endl;
    return 0;
}

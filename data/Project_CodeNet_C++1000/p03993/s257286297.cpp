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
typedef pair<ll,ll> P;
 
 

 
int main(void){
    int n;
    cin>>n;
    map<int,int>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        a--;
        m[i]=a;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(m[m[i]]==i && i<m[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
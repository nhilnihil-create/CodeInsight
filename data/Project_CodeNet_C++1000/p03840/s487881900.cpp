#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
using Graph = vector<vector<int>>;

int main(){
    ll ai,ao,at,aj,al,as,az;
    cin>>ai>>ao>>at>>aj>>al>>as>>az;
    ll ans = 0;

    ll three = min({ai,aj,al});
    ans = three*3 + (ai-three)-(ai-three)%2 + 
        (aj-three)-(aj-three)%2 + (al-three)-(al-three)%2;

    three = min({ai,aj,al})-1;
    if(three < 0) three = 0;
    ll tmp = three*3 + (ai-three)-(ai-three)%2 + 
        (aj-three)-(aj-three)%2 + (al-three)-(al-three)%2;

    ans = max(ans,tmp);

    ans += ao;
    
    cout<<ans<<endl;
}
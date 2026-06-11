#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = ll(1e18)+5;
ll N,K;
vector<ll> a;


ll dfs(int t,vector<bool>& use){
    if(t==N){
        ll temp = 0;
        ll num = 0;
        ll last = 0;
        for(int i=0;i<N;i++){
            if(use[i]){
                num++;
                temp += max(0ll,last+1-a[i]);
                last = max(last+1,a[i]);
            }
            last = max(last,a[i]);
        }
        if(num>=K){
            return temp;
        }
        return INF;
    }
    ll retVal = INF;
    retVal = min(retVal,dfs(t+1,use));
    use[t] = true;
    retVal = min(retVal,dfs(t+1,use));
    use[t] = false;
    return retVal;
}


int main() {
    cin >> N >>K;
    a.resize(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    vector<bool> use(N,false);
    cout << dfs(0,use) << endl;
    return 0;
}
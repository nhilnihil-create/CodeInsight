#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P =pair<ll,ll>;
ll A,B,C,D,E,F;
const ll INF =ll(1e18)+5;
set<ll> water;

void dfs(ll sum){
    if(sum>F){
        return;
    }
    if(water.find(sum) != water.end()){
        return;
    }
    water.insert(sum);
    dfs(sum+A*100);
    dfs(sum+B*100);

}

set<ll> sugar;
void sugarDfs(ll sum){
    if(sum>F){
        return;
    }
    if(sugar.find(sum) != sugar.end()){
        return;
    }
    sugar.insert(sum);
    sugarDfs(sum+C);
    sugarDfs(sum+D);

}

int main() {
    cin >> A >>B >>C >>D >>E >>F;
    dfs(0);
    water.erase(0);
    water.insert(INF);
    sugarDfs(0);
    long double maxN = 0;
    P ans = P(A*100,0);
    for(auto itr = sugar.begin();itr != sugar.end();++itr){
        // cerr <<"*itr=" << *itr << endl; 
        ll needWater = 100* ((*itr + E-1)/E);
        auto witr = water.lower_bound(needWater);
        //  cerr <<"*witr=" << *witr << endl; 
        if(*itr + *witr <= F){
            long double n = ((long double)*itr)/((long double)(*itr+*witr)+(1e-7));
            // cerr <<"n="<< n << endl;
            if(n>maxN){
                maxN = n;
                ans = P((*itr+*witr),*itr);
            }
        }
    }
    cout << ans.first <<" "<< ans.second << endl;
    return 0;
}
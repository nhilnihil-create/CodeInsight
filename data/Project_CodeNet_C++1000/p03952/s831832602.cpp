#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

int main() {
    ll N,x;
    cin >> N >> x;
    if(x==2*N-1 || x==1){
        cout << "No" << endl;
        return 0;
    }
    else cout << "Yes" << endl;

    deque<ll> ans;
    set<ll> se;
    if(x!=2){
        ans.push_back(x-1); se.insert(x-1);
        ans.push_back(x+1); se.insert(x+1);
        ans.push_back(x);   se.insert(x);
        ans.push_back(x-2); se.insert(x-2);
        for(int i=1;i<=2*N;i++){
            if(se.count(i)==1) continue;
            if(ans.size()<N+2){
                ans.push_front(i);
            }
            else ans.push_back(i);
        }
    }
    else{
        ans.push_back(x+1); se.insert(x+1);
        ans.push_back(x-1); se.insert(x-1);
        ans.push_back(x);   se.insert(x);
        ans.push_back(x+2); se.insert(x+2);
        for(int i=1;i<=2*N;i++){
            if(se.count(i)==1) continue;
            if(ans.size()<N+2){
                ans.push_front(i);
            }
            else ans.push_back(i);
        }
    }

    for(int i=0;i<2*N-1;i++){
        cout << ans[i] << endl;
    }

    return 0;
}
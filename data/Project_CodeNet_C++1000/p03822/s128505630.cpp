#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

vector<int> E[100005];

int solve(int cur){
    int res=0,pl=1;
    vector<int> tmp;
    for(auto nxt :E[cur]){
        tmp.push_back(solve(nxt));
    }
    sort(tmp.begin(),tmp.end());
    for(int i=tmp.size()-1;i>=0;i--){
        res=max(res,tmp[i]+(pl));
        pl++;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=2;i<=n;i++){
        cin >> a[i];
        E[a[i]].push_back(i);
    }
    cout << solve(1) << endl;
}

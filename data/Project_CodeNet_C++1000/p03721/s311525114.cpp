#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    long long n,k;
    cin >> n >> k;

    vector <long long> fac(0);
    map <long long, long long> table;

    rep(i,n){
        int a,b;
        cin >> a >> b;
        fac.push_back(a);
        if(table.count(a)){
            table.at(a) += b;
        }
        else{
            table[a] = b;
        }
    }
    sort(all(fac));
    fac.erase(unique(all(fac)), fac.end());

    long long cnt = 0;
    for(auto x:fac){
        cnt += table.at(x);
        if(cnt >= k){
            cout << x << endl;
            return 0;
        }
    }
}

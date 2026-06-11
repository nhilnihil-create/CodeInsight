#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    set<int> se;
    int add = 0;
    rep(i,n){
        if(a[i]>=3200) add++;
        else se.insert(a[i]/400);
    }
    int MIN = se.size();
    if(MIN==0 && add > 0) MIN = 1;
    int MAX = se.size() + add;
    cout << MIN << " " << MAX << endl;
}
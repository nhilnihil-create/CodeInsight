#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
const int max_n = 100000+5;
long long n, W,L,P,c;

long long  v[3*max_n],w[max_n],m[max_n],A[max_n],spf[max_n],co[max_n];  
typedef pair<long, long> pii; 
pii p[max_n];
pii bb[max_n];
struct Cmp {
  bool operator()(const pii &a, const pii &b) {
    return a.second > b.second;
  }
};
void solve(){
    priority_queue<long> ba;
    priority_queue<long, vector<long>, greater<long> > fo;
    vector<long long >  s(2*n+1, 0);
    for(int i=0 ; i<n ; i++){
        s[i+1] = s[i] + v[i];
        fo.push(v[i]);
    }
    for(int i=n ; i<2*n ; i++){
        long long mi = fo.top();
        if(mi < v[i]){
            s[i+1] = s[i] + v[i] - mi;
            fo.pop();
            fo.push(v[i]);
        }else{
            s[i+1] = s[i];
        }
    }
    vector<long long> T(2*n+1);
    for(int i=0 ; i<n ; i++){
        T[i+1] = T[i] + v[3*n -i -1];
        ba.push(v[3*n-i-1]);
    }
    for(int i=n ; i<2*n ; i++){
        long long ma = ba.top();
        if(v[3*n-i-1]<ma){
            T[i+1] = T[i] - ma + v[3*n-i-1];
            ba.pop();
            ba.push(v[3*n-i-1]);
        }else{
            T[i+1] = T[i];
        }
    }
    long long res = -(1LL<<60);
    for(int i=n ; i<=2*n ; i++){
        res = max(res, s[i] - T[3*n -i]);
    }

    cout << res << endl;
}
int main(){
    cin >> n;
    for(int i=0 ; i<n*3 ; i++){
        cin >> v[i];
    }
    solve();
    return 0;
}

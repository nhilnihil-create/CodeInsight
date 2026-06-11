#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<LL, LL>;

int main(){
    LL N, T;
    cin >> N >> T;
    vector<LL>  a(N);
    for(int i = 0;i < N;i++)    cin >> a[i];
    vector<LL>  mina(N), maxa(N);
    set<P> st;
    mina[0] = a[0], maxa[N-1] = a[N-1];
    for(int i = 1;i < N;i++)    mina[i] = min(mina[i-1], a[i]);
    for(int i = N-2;i >= 0;i--) maxa[i] = max(maxa[i+1], a[i]);
    map<LL, LL>  p;
    LL m = 0;
    for(int i = 0;i < N-1;i++)  m = max(m, maxa[i+1]-mina[i]);
    for(int i = 0;i < N-1;i++){
        if(maxa[i+1]-mina[i] == m){
            if(a[i] == mina[i]){
                p[maxa[i+1]]++;
                st.insert(P(a[i], a[i]+m));
            }
            if(a[i+1] == maxa[i+1])    p[mina[i]]++;
        }
    }
    LL ans = 0;
    for(auto& iter : st){
        ans += min(p[iter.first], p[iter.second]);
    }
    cout << ans << endl;
}
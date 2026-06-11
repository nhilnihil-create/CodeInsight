#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N, a;
    cin >> N;
    map<int, int> mp;
    rep(i, N){
        cin >> a;
        if(mp.count(a)) mp[a]++;
        else mp[a] = 1;
    }
    bool able = false;
    map<int, int>::iterator ite;;
    if(mp.size() == 1){
        ite = mp.begin();
        int n = ite->first;
        if(n == N-1 || N >= 2*n) able = true;
    }
    elif(mp.size() == 2){
        ite = mp.begin();
        int a = ite->first;
        ite++;
        int b = ite->first;
        if(a == b+1 || b == a+1){
            int n = max(a, b);
            int m = mp[n-1];
            if(m < n && (n-m)*2 <= N-m) able = true;
        }
    }
    if(able) cout << "Yes" << endl;
    else cout << "No" << endl; 
}
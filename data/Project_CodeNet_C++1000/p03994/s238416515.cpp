#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    vector<ll>cnt(n);
    ll sum = 0;
    rep(i, 0, n){
        cnt[i] = (26-(s[i]-'a'))%26;
        sum += (26-(s[i]-'a'))%26;
    }
    //cout << sum << endl;
    if(sum >= k){
        string t;
        rep(i, 0, n-1){
            if(k-cnt[i]<0||cnt[i]==0){
                t += s[i];
                continue;
                //cout << k << endl;
            }
            k -= cnt[i];
            t += 'a';
            //cout << k << endl;
        }
        t += ((s[n-1]-'a')+k)%26 + 'a';
        cout << t << endl;
        return 0;
    }else{
        //aから何個進むか
        ll add = (k-sum)%26;
        string t;
        rep(i, 0, n)t += 'a';
        //t += ((s[n-1]-'a')+add)%26 + 'a';
        //cout << add << endl;
        while(add>0){
            if(t[n-1]=='z')t[n-1]='a';
            else t[n-1]++;
            add--;
        }
        cout << t << endl;
        return 0;
    }
}
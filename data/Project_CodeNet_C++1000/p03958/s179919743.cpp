#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

int main(){
    ll K,T;
    cin >> K >> T;
    vector<ll> a(T);
    priority_queue<Pll> que;
    rep(i,T){
        cin >> a[i];
        que.push(make_pair(a[i],i));
    }
    ll cnt = 0;
    ll prev = -1;
    rep(i,K){
        auto p = que.top();
        if(prev == p.second){
            que.pop();
            if(!que.empty()){
                auto q = que.top();
                que.pop();
                if(q.first > 1){
                    que.push(make_pair(--q.first, q.second));
                }
                que.push(p);
                prev = q.second;
            }else{
                cnt++;
                if(p.first > 1){
                    que.push(make_pair(--p.first,p.second));
                }
                prev = p.second;
            }
        }else{
            que.pop();
            if(p.first > 1){
                que.push(make_pair(--p.first,p.second));
            }
            prev = p.second;
        }
    }

    cout << cnt << endl;
}

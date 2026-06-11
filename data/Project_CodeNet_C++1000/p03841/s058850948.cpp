#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    int n;
    cin >> n;
    int ans[510*510];
    int x[510];

    vector<pair<int,pair<int,int>>> p; // position, number, count.
    vector<pair<int,pair<int,int>>> q;

    srep(i,1,n+1){
        cin >> x[i];
        ans[x[i]] = i;
        pair<int,pair<int,int>> p_;
        p_.first = x[i];
        p_.second.first = i;
        p_.second.second = i - 1;
        p.push_back(p_);
        p_.second.second = n - i;
        q.push_back(p_);
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end(), greater<pair<int,pair<int,int>>>());

    int now = 1;
    rep(i,n){
        rep(j,p[i].second.second){
            while(true){
                if(p[i].first <= now){
                    cout << "No" << endl;
                    return 0;
                }
                if(ans[now] == 0){
                    ans[now] = p[i].second.first;
                    break;
                }
                now++;
            }
        }
    }

    now = n*n;
    rep(i,n){
        rep(j,q[i].second.second){
            while(true){
                if(now <= q[i].first){
                    cout << "No" << endl;
                    return 0;
                }
                if(ans[now] == 0){
                    ans[now] = q[i].second.first;
                    break;
                }
                now--;
            }
        }
    }

    cout << "Yes" << endl;
    srep(i,1,n*n+1){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
 
 


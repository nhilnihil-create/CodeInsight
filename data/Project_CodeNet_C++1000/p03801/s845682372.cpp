#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
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
    ll a[n];
    vector<pair<ll,int>> v;
    rep(i,n){
        cin >> a[i];
        pair<ll,int> p;
        p.first = a[i];
        p.second = i;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), greater<pair<ll,int>>());
    ll ans[n] = {};

    ll ite = 0;
    int head = 1001001001;
    ll ma = -1;

    while(true){
        if(ite==0){
            head = v[ite].second;
            ma = v[ite].first;
            ite++;
            while(ite<n){
                if(v[ite].first==ma){
                    head = min(head,v[ite].second);
                    ite++;
                }else{
                    break;
                }
            }
        }else{
            ma = v[ite].first;
            head = min(head,v[ite].second);
            ite++;
            while(ite<n){
                if(v[ite].first==ma){
                    head = min(head,v[ite].second);
                    ite++;
                }else{
                    break;
                }
            }
        }

        if(ite==n){
            ans[head] += n * ma;
        }else{
            ans[head] += (ma-v[ite].first) * ite;
        }
        if(ite==n)break;
    }

    rep(i,n){
        cout << ans[i] << endl;
    }

    return 0;
}
 
 

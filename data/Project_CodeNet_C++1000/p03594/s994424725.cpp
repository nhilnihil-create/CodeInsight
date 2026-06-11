#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a,b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,d;
    cin >> h >> w >> d;
    d++;
    int cri = h+w;
    int loop = cri / (d-1) + 1;
    int ln = loop*(d-1);
    vector<vector<int> > vec(ln);
    vector<int> vec1(ln),vec2(ln);
    rep(i,ln/(d-1)){
        if(i % 2 == 0){
            rep(j,d-1){
                vec1[i*(d-1)+j] = 0;
            }
        }else{
            rep(j,d-1){
                vec1[i*(d-1)+j] = 1;
            }
        }
    }
    rep(i,ln/(d-1)){
        if(i % 2 == 0){
            rep(j,d-1){
                vec2[i*(d-1)+j] = 2;
            }
        }else{
            rep(j,d-1){
                vec2[i*(d-1)+j] = 3;
            }
        }
    }
    rep(i,ln/(d-1)){
        if(i % 2 == 0){
            rep(j,d-1){
                vec[i*(d-1)+j] = vec1;
            }
        }else{
            rep(j,d-1){
                vec[i*(d-1)+j] = vec2;
            }
        }
    }
    // rep(i,ln){
    //     rep(j,ln){
    //         cout << vec[i][j];
    //     }
    //     cout << endl;
    // }
    vector<vector<int> > ans(h,vector<int>(w));
    rep(i,h){
        rep(j,w){
            ans[i][j] = vec[i+j][h-1+j-i];
        }
    }
    string ss = "RYGB";
    rep(i,h){
        rep(j,w){
            cout << ss[ans[i][j]];
        }
        cout << endl;
    }
    return 0;
}

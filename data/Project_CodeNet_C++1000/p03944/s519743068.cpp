#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int W,H,N;
    cin >> W >> H >> N;
    vector<vint> S(H,vint(W,0));
    vector<pair<int,int>> P;
    vint A;
    REP(i,N){
        int x,y,a;
        cin >> x >> y >> a;
        P.pb({x,y});
        A.pb(a);
    }

    REP(i,N){
        switch(A[i]){
        case 1:
            REP(j,H){
                REP(k,P[i].first){
                    S[j][k] = 1;
                }
            }
            break;
        case 2:
            REP(j,H){
                for(int k=P[i].first; k<W; k++){
                    S[j][k] = 1;
                }
            }
            break;
        case 3:
            REP(j,P[i].second){
                REP(k,W){
                    S[j][k] = 1;
                }
            }
            break;
        case 4:
            for(int j=P[i].second; j<H; j++){
                REP(k,W){
                    S[j][k] = 1;
                }
            }
            break;
        default:
            break;
        }
    }
    int cnt = 0;
    REP(i,H){
        REP(j,W){
            if(S[i][j] == 0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;

    //mizu
    set<int>mizu;
    rep(i,F){
        rep(j,F){
            if(i*100*A+j*100*B <= F){
                mizu.insert(i*100*A+j*100*B);
            }
        }
    }

    //satou
    set<int>satou;
    rep(i,F){
        rep(j,F){
            if(i*C+j*D <= F){
                satou.insert(i*C+j*D);
            }
        }
    }

    int s =0;
    int sm = 100*A; 
    for(auto i : mizu){
        for(auto j: satou){
            if(i+j <= F && (float)  j /(i+j) <= (float) E/(100+E) ){
                if((float) s/sm  < (float) j /(i+j) ){
                    s = j;
                    sm = i+j;
                }        
            }
        }
    }

    cout << sm << " " << s << endl;


}
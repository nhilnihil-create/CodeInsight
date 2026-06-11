#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;
//using namespace boost::multiprecision;

int main(){

    int n, ma, mb;
    cin >> n >> ma >> mb;

    vector<int> a;
    vector<int> b;
    vector<int> c;

    rep(i,n){
        int tmpa,tmpb,tmpc;
        cin >> tmpa >> tmpb >> tmpc;

        a.pback(tmpa);
        b.pback(tmpb);
        c.pback(tmpc);
    }

    vector<vector<pair<int,int>>> dp(n + 1, vector<pair<int,int>>(8001, mpair(0,INT_MAX / 2)));

    dp[0][4000] = mpair(0,0);

    rep(i,n){
        rep(j, 8001){
            if(dp[i][j].second != INT_MAX / 2){

                //使わなかった場合
                
                //すでになにか購入している場合、0個の情報で塗り替えてはならない
                if(dp[i + 1][j].first != 0){
                    if(dp[i][j].first != 0){
                        if(dp[i + 1][j].second > dp[i][j].second){
                            dp[i + 1][j] = dp[i][j];
                        }
                    }
                }else{
                    dp[i + 1][j] = dp[i][j];
                }

                //つかう場合
                int d = a[i] * mb - b[i] * ma;

                if(dp[i + 1][j + d].first == 0){
                    dp[i + 1][j + d] = mpair(1, dp[i][j].second + c[i]);
                }else{
                    if(dp[i + 1][j + d].second > dp[i][j].second + c[i]){
                        dp[i + 1][j + d] = mpair(1, dp[i][j].second + c[i]);
                    }
                }

                if(j == 4000){
                    if(dp[i + 1][j + d].first == 0){
                        dp[i + 1][j + d] = mpair(1, dp[i][j].second + c[i]);
                    }else{
                        if(dp[i + 1][j + d].second >  c[i]){
                            dp[i + 1][j + d] = mpair(1, c[i]);
                        }
                    }
                }
            }
        }
    }

    if(dp[n][4000].first != 0){
        cout << dp[n][4000].second << endl;
    }else{
        cout << -1 << endl;
    }


    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

int main(){
    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    set<int> Ws,Ss;
    vector<int> W(0),S(0);
    for (int i=0; i<=F; i+=A*100){
        for (int j=B*100; i+j<=F; j+=B*100) {
            if (!Ws.count(i+j)) {
                Ws.insert(i+j);
                W.push_back(i+j);
            }
        }
    }
    for (int i=0; i<=F; i+=B*100){
        for (int j=A*100; i+j<=F; j+=A*100) {
            if (!Ws.count(i+j)) {
                Ws.insert(i+j);
                W.push_back(i+j);
            }
        }
    }

    for (int i=0; i<=E*F/100+1; i+=C){
        for (int j=0; i+j<=E*F/100+1; j+=D) {
            if (!Ss.count(i+j)) {
                Ss.insert(i+j);
                S.push_back(i+j);
            }
        }
    }

    for (int i=0; i<=E*F/100+1; i+=D){
        for (int j=0; i+j<=E*F/100+1; j+=C) {
            if (!Ss.count(i+j)) {
                Ss.insert(i+j);
                S.push_back(i+j);
            }
        }
    }   
    
    sort(S.begin(),S.end());

    double n_tmp;
    int s_tmp,w_tmp;
    n_tmp = -1.0;
    rep(i,W.size()) {
        rep(j,S.size()) {
            int X;
            X = E*W[i]/100;
            if (S[j]>X) {
                continue;
            }
            else {
                if (n_tmp<(1.0*S[j]/(W[i]/100)) && (W[i]+S[j])<=F) {

                    n_tmp = (1.0*S[j]/(W[i]/100));
                    s_tmp = S[j];
                    w_tmp = W[i];
                }
            }
        }
    }

    cout << w_tmp+s_tmp << " " << s_tmp << endl;

    
}

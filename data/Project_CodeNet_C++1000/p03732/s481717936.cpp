#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll N,W;
    cin>>N>>W;
    vector<pair<ll,ll>> P;
    for (int i=0;i<N;i++) {
        ll w,v;
        cin>>w>>v;
        P.push_back(make_pair(w,v));
    }
    sort(P.begin(),P.end());
    ll wmin = P[0].first;
    vector<vector<ll>> X(4);
    for (auto p:P) {
        X[p.first-wmin].push_back(p.second);
    }

    vector<vector<ll>> sum(4,vector<ll>(101,0)); //先頭からn個までの和

    for (int i=0;i<4;i++){
        sort(X[i].begin(),X[i].end(),greater<ll>());
        for (int j=1;j<=X[i].size();j++) {
            sum[i][j] += sum[i][j-1] + X[i][j-1];
        }
    }

    ll ans = -1;

    for (int i=0;i<=X[0].size();i++) {
        for (int j=0;j<=X[1].size();j++) {
            for (int k=0;k<=X[2].size();k++) {
                for (int l=0;l<=X[3].size();l++) {
                    ll vsum;
                    ll weight = wmin*i + (wmin+1)*j + (wmin+2)*k + (wmin+3)*l;
                    if (weight <= W) {
                        vsum = sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l];
                        ans = max(vsum,ans); 
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
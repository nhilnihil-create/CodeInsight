#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int cnt[100010];
int main()
{
    int N,M;
    cin >> N >> M;
    vector<vector<int>>p(M,vector<int>());
    rep(i,N){
        int X;
        cin >> X;
        p[X%M].push_back(X);
    }
    rep(i,M){
        sort(p[i].begin(),p[i].end());
    }
    ll ans=0;
    for(int i=0;i<=M-i;i++){
        if((i==0)||(M%2==0&&i==(M/2))){
            ans+=p[i].size()/2;
        }
        else{
            int ci=p[i].size();
            int cres=p[M-i].size();
            
            if(ci>=cres){
                ans+=cres;
                int cn=0;
                rep(j,p[i].size()){
                    if((j>0&&p[i][j]==p[i][j-1])){
                        cn++;j++;
                    }
                }
                ans+=min(cn,(ci-cres)/2);
            }
            else{
                ans+=ci;
                int cn=0;
                rep(j,p[M-i].size()){
                    if((j>0&&p[M-i][j]==p[M-i][j-1])){
                        cn++;j++;
                    }
                }
                ans+=min(cn,(cres-ci)/2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

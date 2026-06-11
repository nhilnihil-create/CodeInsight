#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    vector<vector<char>> img(N,vector<char>(N)), tmpl(M,vector<char>(M));
    rep(i,0,N)rep(j,0,N) cin>>img.at(i).at(j);
    rep(i,0,M)rep(j,0,M) cin>>tmpl.at(i).at(j);
    
    bool mismatch=false;
    rep(ni,0,N-M){
        rep(nj,0,N-M){
            mismatch=false;
            rep(mi,0,M){
                rep(mj,0,M){
                    char c_img=img.at(ni+mi).at(nj+mj),
                        c_tmpl=tmpl.at(mi).at(mj);
                    
                    if(c_img!=c_tmpl){
                        mismatch=true;
                        break;
                    }
                }
                if(mismatch) break;
            }
            if(!mismatch) break;
        }
        if(!mismatch) break;
    }

    string ans="Yes";
    if(mismatch) ans="No";
    cout<<ans<<endl;
}
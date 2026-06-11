#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    int l;
    l=s.size();
    int lmax,ans=1000;
    string s2,s3;
    rep(i,l){
        s2=s[i];
        int k=1;
        lmax=i+1;
        rep(j,l){
            s3=s[j];
            if(s2!=s3){
                ++k;
            }
            else{
                lmax=max(k,lmax);
                k=1;
            }
        }
        lmax=max(k,lmax);
        ans=min(ans,lmax);
    }

    cout << ans-1 << endl;

    return 0;
}
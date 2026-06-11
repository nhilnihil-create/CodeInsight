#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>
#include<climits>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

#define DEBUGMODE 0
#define int long long
#define MOD (1000000007l)
#define EPS ((double)0.000000001)
#define rep(i,s,n) for(int (i)=(s);i<(int)(n);(i)++)
#define rrep(i,s,n) for(int (i)=(int)(n)-1;(i)>=(s);(i)--)

signed main(){
    int ans=1;
    int N;
    cin>>N;
    string s[2];

    cin>>s[0];
    cin>>s[1];

    int bef=0;
    rep(i,0,s[0].size()){
        if(s[0][i]==s[1][i]){
            if(bef==0){
                ans*=3;
            }
            if(bef==1){
                ans*=2;
            }
            if(bef==2){
                ans*=1;
            }
            bef=1;
        }
        else{
            if(bef==0){
                ans*=3;
                ans*=2;
            }
            if(bef==1){
                ans*=2;
                ans*=1;
            }
            if(bef==2){
                ans*=3;
            }
            bef=2;
            i++;
        }
        ans%=MOD;
    }
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

vector<LL> v;

int main(){
    int N,K;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        LL t;
        cin >> t;
        v.pb(t);
    }
    sort(ALL(v));
    int l=0,r=N;
    while(l<r){
        vector<vector<bool>> dp(N+1,vector<bool> (K+1));
        int mid=(r+l)/2;
        LL t=v[mid];
        if(t>=K){
            if(r==mid){
                break;
            }
            r=mid;
            continue;
        }
        v[mid]=0;
        dp[0][0]=true;
        for(int i=0;i<N;i++){
            for(int j=0;j<K;j++){
                if(dp[i][j]){
                    dp[i+1][j]=true;
                    if(j+v[i]<=K) dp[i+1][j+v[i]]=true;
                }
            }
        }
        bool c=false;
        for(int i=K-t;i<K;i++){
            if(dp[N][i]){
                c=true;
            }
        }
        if(c){
            if(r==mid){
                break;
            }
            r=mid;
        }
        else{
            if(l==mid){
                break;
            }
            l=mid;
        }
        v[mid]=t;
    }
    cout << r << endl;
    return 0;
}
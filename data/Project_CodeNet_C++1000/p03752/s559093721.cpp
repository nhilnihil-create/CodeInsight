#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define prime 1000000007
#define INF 40000000000000000
int dx8[8]={-1,0,1,1,1,0,-1,-1};
int dy8[8]={1,1,1,0,-1,-1,-1,0};
int dx4[4]={-1,0,1,0};
int dy4[4]={0,-1,0,1};
signed main(void){
    int n,k;cin>>n>>k;
    int hight[n];rep(i,n)cin>>hight[i];
    vector<int>V(n,0);
    rep(i,k)V[n-i-1]=1;
    int ans=INF;
    do{
        vector<int>see;
        rep(i,n){
            if(V[i])see.push_back(i);
        }
        int now=0,highest=0,sum=0;
        rep(i,n){
            if(i==see[now]){
                if(hight[i]<=highest){
                    highest++;
                    sum+=highest-hight[i];
                }
                now++;
            }
            highest=max(highest,hight[i]);
        }
        ans=min(ans,sum);
    }while(next_permutation(all(V)));
    cout<<ans<<endl;
}
        

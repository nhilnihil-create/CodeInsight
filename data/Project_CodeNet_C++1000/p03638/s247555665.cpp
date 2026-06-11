#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    int ans[110][110];
    int H,W,N;
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>H>>W>>N;
        vector<pair<int,int>>a;
        for(int u=1;u<=N;u++){
            int v;
            cin>>v;
            a.push_back({v,u});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        int r=1,c=1,d=1;
        for(auto p:a){
            int t=p.first,i=p.second;
            while(r<=H&&t>0){
                if(d==1){
                    while(c<=W&&t>0){
                        ans[r][c]=i;
                        t--;
                        c++;
                    }
                    if(c>W){
                        d=0;
                        r++;
                        c=W;
                    }
                }
                if(d==0){
                    while(c>0&&t>0){
                        ans[r][c]=i;
                        t--;
                        c--;
                    }
                    if(c==0){
                        d=1;
                        r++;
                        c=1;
                    }
                }
            }
        }
        for(int r=1;r<=H;r++){
            for(int c=1;c<=W;c++){
                cout<<ans[r][c]<<" ";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
set<pii>sts,ps;
ll h,w,n,cnt[11];
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;ps.insert({x,y});
        for(int xa=0;xa<3;xa++){
            for(int ya=0;ya<3;ya++){
                int nx=x-xa,ny=y-ya;
                if(nx<=0||ny<=0||nx+2>h||ny+2>w)continue;
                sts.insert({nx,ny});
            }
        }
    }
    ll lef=(h-2)*(w-2);
    for(auto el:sts){
        int c=0;
        int x=el.first,y=el.second;
        for(int xa=0;xa<3;xa++){
            for(int ya=0;ya<3;ya++){
                c+=ps.count({x+xa,y+ya});
            }
        }
        cnt[c]++;
        lef--;
    }
    cnt[0]=lef;
    for(int i=0;i<10;i++)cout<<cnt[i]<<'\n';
    return 0;
}

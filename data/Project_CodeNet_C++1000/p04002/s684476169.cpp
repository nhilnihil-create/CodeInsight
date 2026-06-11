#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <string>
#include <map>
#include <utility>
const int maxn = 1e5+1;
typedef long long ll;
using namespace std;
std::map< std::pair<int,int> , int> M;
int y[maxn];
int x[maxn];
ll cnt[10];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll H,W;
    cin>>H>>W;
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i){
        int a,b;
        cin>>a>>b;
        y[i]=a;
        x[i]=b;
        M[make_pair(a,b)]=1;
    }
    for(int dy=0; dy<3; ++dy)
        for(int dx=0; dx<3; ++dx)
            for(int i=1; i<=n; ++i){
                int base_y=y[i]-dy;
                int base_x=x[i]-dx;
                int good=1;
                if (base_x+2>W)
                    good=0;
                if (base_y+2>H)
                    good=0;
                if (base_x<=0)
                    good=0;
                if (base_y<=0)
                    good=0;
                    for(int z=dy+1; z<3; ++z)
                        for(int e=0; e<3; ++e)
                            if (M.count(make_pair(base_y+z,base_x+e)))
                                good=0;

                    for(int e=dx+1; e<3; ++e)
                        if (M.count(make_pair(y[i],base_x+e)))
                            good=0;

               // cout<<i<<" "<<dy<<" "<<dx<<" : "<<good<<endl;
                if (good){
                    int cur=0;
                    for(int e=0; e<3; ++e)
                        for(int z=0; z<3; ++z)
                            cur+=M.count(make_pair(base_y+z,base_x+e));
                    cnt[cur]++;
                   // cout<<cur<<endl;
                }
            }
    cnt[0]=(H-2)*(W-2);
    for(int i=1; i<=9; ++i)
        cnt[0]-=cnt[i];
    for(int i=0; i<=9; ++i)
        cout<<cnt[i]<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

map<P,bool> mp;
vector<P> v;

int main(){
    LL H,W;
    int N;
    cin >> H >> W >> N;
    for(int i=0;i<N;i++){
        LL a,b;
        cin >> a >> b;
        mp[make_pair(a,b)]=true;
        v.push_back(make_pair(a,b));
    }
    LL ans[10];
    memset(ans,0,sizeof(ans));
    for(auto p:v){
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int count=0;
                bool h=false;
                for(int s=-1;s<=1;s++){
                    for(int t=-1;t<=1;t++){
                        if(1<=p.first+i+s&&p.first+i+s<=H&&1<=p.second+j+t&&p.second+j+t<=W){
                            if(mp[make_pair(p.first+i+s,p.second+j+t)]) count++;
                        }
                        else h=true;
                    }
                }
                if(h) continue;
                ans[count]++;
            }
        }
    }
    LL sum=0;
    for(int i=1;i<10;i++){
        sum+=ans[i]/i;
    }
    cout << (H-2)*(W-2)-sum << endl;
    for(int i=1;i<10;i++){
        cout << ans[i]/i << endl;
    }
    return 0;
}
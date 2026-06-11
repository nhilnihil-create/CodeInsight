#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool w[3005],s[3005];

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    //水を全探索
    rep(i,35)rep(j,35){
        int x=a*i*100+b*j*100;
        if(x<=3000)w[x]=true;
    }
    //砂糖を全探索
    rep(i,3005)rep(j,3005){
        int x=c*i+d*j;
        if(x<=3000)s[x]=true;
    }
    double per=-1;
    int answs=0,anss=0;
    //あり得る組み合わせについて全探索
    for(int i=100; i<=3000; ++i){
        for(int j=0; j<=3000; ++j){
            if(!w[i]||!s[j]||i+j>f)continue;
            if(j*100.0/(i+j)>per){
                if(j*100>i*e)continue;
                per=j*100.0/(i+j);
                answs=i+j;
                anss=j;
            }
        }
    }
    cout<<answs<<" "<<anss<<endl;
}
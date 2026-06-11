#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    int a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    int ansf=1,anss=0;
    int nowf=0, nows=0;
    rep(i,35){
        rep(j,35){
            nowf=a*100*i+b*100*j;
            if(i==0 && j==0) continue;
            if(a*100*i+b*100*j>f) break;
            int cnt=0;
            while(1){
                if(nowf+cnt*d>f) break;
                int lim=nowf/100;
                lim*=e;
                if(cnt*d>lim) break;
                int cc=max(0, min(lim-cnt*d, f-nowf-cnt*d))/c;
                nows=cnt*d+c*cc;
                if(nows*ansf>anss*nowf){
                    anss=nows;
                    ansf=nowf;
                }
                cnt++;
            }
        }
    }
    if(ansf==1){
        cout<<100*a<<" "<<0<<endl;
        return 0;
    }
    cout<< ansf+anss <<" "<< anss <<endl;
    return 0;
}
#include <bits/stdc++.h>
#define REP(i,n) for(LL i=0;i<(LL)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pll pair<LL,LL>

using namespace std;


int main(){

    LL W,H;cin>>W>>H;
    LL p[W],q[H];
    REP(i,W)cin>>p[i];
    REP(i,H)cin>>q[i];
    priority_queue<LL,vector<LL>,greater<LL> > quep;
    priority_queue<LL,vector<LL>,greater<LL> > queq;
    REP(i,W)quep.push(p[i]);
    REP(i,H)queq.push(q[i]);
    int cntp=0,cntq=0;

    LL ans=0;

    while(cntp<W||cntq<H){
        int nextp=1000000000;
        int nextq=1000000000;
        if(cntp<W){
            nextp=quep.top();
        }
        if(cntq<H){
            nextq=queq.top();
        }

        if(nextp<nextq){
            ans+=nextp*(H-cntq+1);
            cntp++;
            quep.pop();
        }else{
            ans+=nextq*(W-cntp+1);
            cntq++;
            queq.pop();
        }
    }
    cout<<ans<<endl;



    return 0;
}
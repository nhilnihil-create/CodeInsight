#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

int H,W,d;


int main(){

    cin>>H>>W>>d;
    string col1="";
    string col2="";
    REP(i,d)col1+="R",col2+="G";
    REP(i,d)col1+="Y",col2+="B";
    REP(i,d)col1+="R",col2+="G";

    char ans[H][W];


    for(int j=0;j<=H*W;j+=d){
        string color = (j%(2*d)==0 ? col1:col2);
        int index = 2*d;
        int sj = j;
        REP(i,H){
            REP(k,d){
                if(sj+k>=W||sj+k<0)continue;
                ans[i][sj+k]=color[index+k];
            }
            sj--;
            index -=(d==1 ? 1:2);
            if(index==0)index=2*d;
        }
    }


    REP(i,H){
        REP(j,W)cout<<ans[i][j];
        cout<<endl;
    }

    return 0;
}
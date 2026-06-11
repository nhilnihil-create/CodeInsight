#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=3105,INF=1<<30;
char S[MAX][MAX],ans[MAX][MAX];

int main(){
    
    int H,W,D;cin>>H>>W>>D;
    string T="RYGB";
    
    for(int i=100;i<=2000;i+=D){
        for(int j=100;j<=2000;j+=D){
            int c=((i-100)/D)%2*2+((j-100))/D%2;
            for(int x=0;x<D;x++){
                for(int y=0;y<D;y++){
                    S[i+x][j+y]=T[c];
                }
            }
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans[i][j]=S[i+1000+j][i+1000-j];
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;

    int w=100*A,s=0;
    for(int a=0;a*100*A<=F;a++){
        for(int b=0;(a*A+b*B)*100<=F;b++){
            int ww=(a*A+b*B)*100;
            int maxs=min(F-ww,ww/100*E);
            for(int c=0;c*C<=maxs&&c<30;c++){
                int ss=(maxs-c*C)/D*D+c*C;
                if(s*(ww+ss)<ss*(w+s)){
                    w=ww;
                    s=ss;
                }                
            }
        }
    }

    cout<<w+s<<" "<<s<<endl;
}
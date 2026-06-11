#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int A,B,C,D,E,F;cin>>A>>B>>C>>D>>E>>F;
    int resx=0,resy=0;
    double buf=-1;
    for(double a=0;a*A*100<=F;a++){
        for(double b=0;(b*B+a*A)*100<=F;b++){
            for(double c=0;(a*A+b*B)*100+c*C<=F;c++){
                for(double d=0;(a*A+b*B)*100+c*C+d*D<=F;d++){
                    if((c*C+d*D)<=E*(a*A+b*B))if(chmax(buf,(c*C+d*D)/(a*A+b*B))){resx=(a*A+b*B)*100+c*C+d*D;resy=c*C+d*D;}
                }
            }
        }
    }
    cout<<resx<<" "<<resy<<endl;
}
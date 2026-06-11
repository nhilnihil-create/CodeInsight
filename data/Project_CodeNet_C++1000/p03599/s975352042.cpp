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
    
    double con=0.0;
    int sumw=100*A,sums=0;
    for(int a=0;a<=30;a++){
        for(int b=0;b<=30;b++){
            for(int c=0;c<=ceil((double)F/C);c++){
                for(int d=0;d<=ceil((double)F/D);d++){
                    int tmpw=100*A*a+100*B*b;
                    int tmps=C*c+D*d;
                    if(tmpw+tmps<=F && tmps*100<=tmpw*E && con<(double)tmps/(tmpw+tmps)){
                        con=(double)tmps/(tmpw+tmps);
                        sumw=tmpw;
                        sums=tmps;
                    }
                }
            }
        }
    }

    cout<<sumw+sums<<" "<<sums<<endl;
}


 
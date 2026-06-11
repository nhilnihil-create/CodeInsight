#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll A, B, C, D, E, F, ans1=0, ans2=0, tmp=0;
double rate=-1.0;

signed main(){
    cin >> A >> B >> C >> D >> E >> F;
    for(int i=0;100*A*i<=F;i++) {
        tmp = F-100*A*i;
        for(int j=0;100*B*j<=tmp;j++) {
            tmp = F-100*A*i-100*B*j;
            for(int l=0;l*C<=tmp;l++) {
                tmp = F-100*A*i-100*B*j-l*C;
                for(int k=0;k*D<=tmp;k++) {
                    if(E*(100*A*i+100*B*j+l*C+k*D)>=(100+E)*(l*C+k*D)) {
                        double v1 = (double)l*(double)C+(double)k*(double)D;
                        double v2 = 100.0*(double)A*(double)i+100.0*(double)B*(double)j+(double)l*(double)C+(double)k*(double)D;
                        if(rate<100.0*(double)v1/(double)v2) {
                            rate = 100.0*v1/v2;
                            ans1 = 100*A*i+100*B*j+l*C+k*D;
                            ans2 = l*C+k*D;
                        }
                    }
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
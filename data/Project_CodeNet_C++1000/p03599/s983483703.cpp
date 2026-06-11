#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double percent=0.0;
    int sum,sugar=0,water=0;
    for (int i=0; i<=30; i++) {
        for (int j=0; j<=30; j++) {
            for (int k=0; k<=100; k++) {
                for (int l=0; l<=100; l++) {
                    int water_weight=a*i+b*j;
                    int sugar_weight=c*k+d*l;
                    sum=100*water_weight+sugar_weight;
                    if (sum<=f&&sugar_weight<=water_weight*e) {
                        if (percent<(double)sugar_weight/(double)sum) {
                            percent=(double)sugar_weight/(double)sum;
                            water=water_weight*100;
                            sugar=sugar_weight;
                        }
                    }
                }
            }
        }
    }
    if (percent==0) water=100*a;
    cout<<water+sugar<<" "<<sugar<<endl;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    set<int> water_set, sugar_set;

    //water
    for(int i=0;i<30;i++){
        for(int j=0;j<=30;j++){
            if(i==0&&j==0) continue;
            int w = 100*a*i+100*b*j;
            if(w>f)break;
            if(w<=f)water_set.insert(w);
        }
    }

    //sugar
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            int s = c*i+d*j;
            if(s>f)break;
            if(s<=f)sugar_set.insert(s);
        }
    }
    
    double maxratio = -1.0;
    int sw=0,s=0;
    for(int x:water_set){
        for(int y:sugar_set){
            if(x+y>f)break;
            if((x/100)*e<y)break;
            double ratio = (double)y/(x+y);
            if(maxratio<ratio){
                maxratio = ratio;
                sw = (x+y);s = y;
            }
        }
    }
    cout << sw << " " << s << endl;
    return 0;
}  
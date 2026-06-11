#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll > P;
typedef pair<P,ll>Q;

int main(void){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int water = 0;
    int sato = 0;
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i==0 && j==0)continue;
            int t = 100*(a*i+b*j);
            if(t>f)continue;
            int lim = e*(a*i+b*j);
            for(int k=0;k<lim;k++){
                for(int l=0;l<lim;l++){
                    int s = c*k+d*l;
                    if(s>lim)continue;
                    int sum = t+s;
                    if(sum>f)continue;
                    if(water==0 && sato==0){
                        water = t;
                        sato = s;
                    }
                    else{
                        if(t*sato<s*water){
                            sato = s;
                            water = t;
                        }
                    }
                }
            }
        }
    }
    cout<<water+sato<<" "<<sato<<endl;
    return 0;
}
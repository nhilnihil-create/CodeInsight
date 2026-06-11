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
typedef pair<int,int> P;



int main(void){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int ans1=0,ans2=0; 
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(i==0 && j==0)continue;
            if(100*(a*i+b*j)>f)continue;
            int limit = e*(a*i+b*j);
            for(int k=0;k<=limit;k++){
                for(int l=0;l<=limit;l++){
                    if(c*k+d*l>limit)continue;
                    int tmp1 = 100*(a*i+b*j)+c*k+d*l;
                    int tmp2 = c*k+d*l;
                    if(tmp1>f)continue;
                    if(ans1==0 && ans2==0){
                        ans1=tmp1;
                        ans2=tmp2;
                        continue;
                    }
                    if(tmp2*ans1>ans2*tmp1){
                        ans1=tmp1;
                        ans2=tmp2;
                    }
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
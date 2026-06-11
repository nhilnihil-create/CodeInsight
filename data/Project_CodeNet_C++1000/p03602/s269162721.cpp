#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#include<list>
#include<limits>
#include<bitset>
#include<ctype.h>
#include<set>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007LL;
const ll INF=1000000000;
const int MAX=100001;
struct edge{int to,cost;};
typedef pair<int,int> P;
ll C[1000][1000];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll a[301][301];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    ll ans=0;
    bool f[301][301]={false};
    for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][k]+a[k][j]<a[i][j]){
                cout<<-1<<endl;
                return 0;
            }
            if(i!=k&&j!=k&&a[i][j]==a[i][k]+a[k][j]){
                f[i][j]=true;
            }
        }
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(!f[i][j]){
                ans+=a[i][j];
            }
        }
    }
    cout<<ans<<endl;
}

                           

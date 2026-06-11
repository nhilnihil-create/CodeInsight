#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;


typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

vector<int> G[100005];
std::vector<P> tree[100010];

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};

#define p(x) cout<<x<<endl;
#define e cout<<endl;
#define pe(x) cout<<x<<" ";
#define re(i,a,b) for(i=a;i<=b;i++)

ll i,j,k,l,ii,jj;
ll n,m,ans=0,sum,num=0;
ll a[100005],b[100005],dame[100005];
bool start=false;


int main(){
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(i=30;i>=-1;i--){
        /*if(!start && k & 1<<i){
            start=true;
        }
        if(!start)continue;*/
        if(k & 1<<i || i==-1){
            sum=0;
            for(j=0;j<n;j++){
                bool flag=false;
                for(ii=0;ii<num;ii++){
                    if(a[j] & 1<<(dame[ii]))flag=true;
                }
                if(i!=-1 && (a[j] & 1<<i))flag=true;
                if(!flag)sum+=b[j];
            }
            ans = max(sum,ans);
            sum=0;
        }else{
            dame[num]=i;
            num++;
        }
    }
    p(ans);
    return 0;
    
}

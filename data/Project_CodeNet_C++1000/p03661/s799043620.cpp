#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

#define INF 1<<21
#define MAX 100005
#define MOD 10e9+7

int main(){
    int N;
    int a[200005];
    long long x=0,y=0;
    long long ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i];
        y+=a[i];
    }
    x=a[0];y-=a[0];
    ans=llabs(x-y);
    for(int i=1;i<N-1;i++){
        x+=a[i];
        
        y-=a[i];
        ans=min(ans,llabs(x-y));
    }
    cout<<ans<<endl;
}

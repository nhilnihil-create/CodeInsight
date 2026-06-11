#include <cstdio>
#include <algorithm>
#include <cstring>

#define re register int

using namespace std;

const int maxn=200010;

int n;
int a[200100];

inline bool check(int x){
    for(re i=0;i<=n-1;i++){
        if((a[n-i]<x&&a[n-i-1]<x)||(a[n+i]<x&&a[n+i+1]<x))
            return false;
        if((a[n-i]>=x&&a[n-i-1]>=x)||(a[n+i]>=x&&a[n+i+1]>=x))
            return true;
    }
    return a[(n<<1)-1]>=x;
}
int main(){
    scanf("%d",&n);
    for(re i=1;i<=(n<<1)-1;i++){
        scanf("%d",&a[i]);
    }
    
    int l=1,r=(n<<1)-1,ans=0;
    
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
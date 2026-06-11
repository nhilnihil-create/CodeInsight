#include <iostream>
using namespace std;
const int N = 2000000 + 10;

int n,a[N],b[N];
int M(int x,int y,int z){
    if((x-y)*(x-z)<=0) return x;
    if((y-x)*(y-z)<=0) return y;
    return z;
}
int cac() {
    int dp[102][102];
    for(int i=1;i<=2*n-1;i++) dp[1][i]=a[i];
    for(int i=2;i<=n;i++){
        for(int j=i;j<=2*n-i;j++){
            dp[i][j] = M(dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]);
        }
    }
    printf("%d\n", dp[n][n]);
}
int chk(int x) {
    //printf("chk %d\n", x);
    for(int i=1;i<=2*n-1;i++) b[i]=a[i]<=x?0:1;
    int mid=n;
    int lb=mid-1,rb=mid+1;

    if(b[mid]==b[mid-1]) return b[mid]==0?1:0;
    if(b[mid]==b[mid+1]) return b[mid]==0?1:0; 
    
    while(lb>=2) {
        if(b[lb]!=b[lb+1] && b[lb]!=b[lb-1]) lb--;
        else break;
    }
    while(rb<2*n-1) {
        if(b[rb]!=b[rb-1] && b[rb]!=b[rb+1]) rb++;
        else break;
    }
    //printf("[%d, %d]\n", lb,rb);
    int R = min(mid-lb, rb-mid);
    if(lb==1 && rb==2*n-1) return (b[mid] ^ (R&1))==0?1:0;


    // [lb,mid,rb]

    if (mid-lb <= rb-mid) {
        int x1 = b[lb-1];    
        int x2 = b[mid] ^ (R&1);
        return x1 == 0 ? 1 : 0;
    } else {
        int x1 = b[rb+1];
        int x2 = b[mid] ^ (R&1);
        return x1 == 0 ? 1 : 0;
    }
}   

int main() {
    scanf("%d", &n);
    for(int i=1;i<=2*n-1;i++){
        scanf("%d",&a[i]);
        //a[i]=i;
    }
    //random_shuffle(a+1,a+1+n);
    int lef = 0, rig = n<<1|1;
    while(rig-lef>1) {
        int mid = (lef + rig) >> 1;
        if (chk(mid)) rig = mid;
        else lef = mid;
    }
    printf("%d\n", rig);
    //cac();
}



/*#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000];
int n;
int main(){
    int i;
    
  //  freopen("/Users/joseunghyeon/Downloads/in (2)/eval_input.txt","r",stdin);
    int TC, TT;
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&w[i]);
        sort(w+1,w+n+1);
        printf("Case #%d\n",TT);
        if(w[n]-w[1]>1){
            printf("No\n");
            continue;
        }
        if(w[n]-w[1]==0){
            if(w[1] <= n/2 || w[1] == n-1)printf("Yes\n");
            else printf("No\n");
            continue;
        }
        for(i=1;i<n;i++)if(w[i]!=w[i+1])break;
        int t = i;
        if(t + 1 <= w[n] && t + (n-t)/2 >= w[n])printf("Yes\n");
        else printf("No\n");
    }
}
*/


/*#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int main(){
    char fp[200];
    
    int T[2]={6,18};
    freopen("/Users/joseunghyeon/Downloads/in (2)/eval_input.txt","w",stdout);
    printf("%d\n",T[0]+T[1]);
    for(int TTT = 0; TTT < 2; TTT++){
        for(int TT=0;TT< T[TTT];TT++){
            fprintf(stderr,"%d %d\n",TTT,TT);
            sprintf(fp, "/Users/joseunghyeon/Downloads/in (2)/%d_%02d.txt", TTT, TT);
            freopen(fp, "r",stdin);
            int n, a;
            scanf("%d",&n);
            printf("%d\n",n);
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                printf("%d",a);
                if(i!=n-1)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
*/

/*#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int main(){
    char fp[200];
    int TC = 0;
    int T[2]={6,18};
    freopen("/Users/joseunghyeon/Downloads/out (2)/eval_output.txt","w",stdout);
    for(int TTT = 0; TTT < 2; TTT++){
        for(int TT=0;TT< T[TTT];TT++){
            fprintf(stderr,"%d %d\n",TTT,TT);
            sprintf(fp, "/Users/joseunghyeon/Downloads/out (2)/%d_%02d.txt", TTT, TT);
            freopen(fp, "r",stdin);
            char rr[10];
            scanf("%s",rr);
            printf("Case #%d\n%s\n",++TC,rr);
        }
    }
    return 0;
}*/


#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, F[4100000], InvF[4100000];
int D[2010][2010], Mod = 1000000007, T[2010];
int Pow(int a, int b){
    int r = 1;
    while(b){
        if(b&1)r=1ll*r*a%Mod;
        a=1ll*a*a%Mod;b>>=1;
    }
    return r;
}
int HH(int a, int b){
    return 1ll * F[a+b-1] * InvF[b] % Mod * InvF[a-1] % Mod;
}
int main(){
    int i, j;
    F[0]=1;
    for(i=1;i<4100000;i++){
        F[i]=1ll*F[i-1]*i%Mod;
    }
    InvF[i-1] = Pow(F[i-1], Mod - 2);
    for(i=i-1;i>=1;i--)InvF[i-1] = 1ll*InvF[i]*i%Mod;
    scanf("%d%d",&n,&m);
    if(m == 1){
        printf("1\n");
        return 0;
    }
    D[1][2] = 1;
    for(i=1;i<n;i++){
        for(j=2;j<=i+1;j++){
            T[2] = (T[2] + D[i][j])%Mod;
            T[j+2] = (T[j+2] + Mod - D[i][j])%Mod;
        }
        int s = 0;
        for(j=2;j<=i+3;j++){
            s = (s+T[j])%Mod;
            T[j] = 0;
            D[i+1][j] = 1ll*s*HH(i*m-j+3, m-2)%Mod;
        }
    }
    int s = 0;
    for(i=2;i<=n+1;i++){
        s = (s + D[n][i])%Mod;
    }
    printf("%lld\n",1ll*s*F[n]%Mod);
}

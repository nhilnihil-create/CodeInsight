#include<stdio.h>
#include<algorithm>
using namespace std;
int n, L, w[110], c1, c2, R[110], RC, s;
int main(){
    int i;
    scanf("%d%d",&L,&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        if(w[i]%2){
            if(!c1)c1=i;
            else if(!c2)c2=i;
            else{
                printf("Impossible\n");
                return 0;
            }
        }
    }
    if(c1)swap(w[1],w[c1]);
    if(c2)swap(w[n],w[c2]);
    for(i=1;i<=n;i++)printf("%d ",w[i]);
    printf("\n");
    for(i=1;i<=n;i++){
        R[++RC] = w[i];
        if(i==1){
            if(w[i] == 1)R[RC]++;
            else R[RC]--;
        }
        s += R[RC];
        if(s > L){
            R[RC] -= (s-L);
            s=L;
        }
        if(s==L)break;
    }
    if(s<L){
        if(n>=2 && w[n]%2==1)R[RC] += (L-s);
        else R[++RC] = 1;
    }
    printf("%d\n",RC);
    for(i=1;i<=RC;i++)printf("%d ",R[i]);
}
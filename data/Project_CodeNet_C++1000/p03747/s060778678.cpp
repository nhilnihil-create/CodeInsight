#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,t;
    scanf("%d%d%d",&n,&l,&t);
    int x[n], w[n];
    for (int i =0 ; i < n; i++){
        scanf("%d%d",&x[i],&w[i]);
        if (w[i] == 2) w[i] = -1;
    }
    int finalpos[n];
    int P[n];
    for (int i = 0; i < n; i++){
        finalpos[i] = P[i] = ((x[i] + w[i]*t)%l + l)%l;
        //printf("%d %d %d\n",x[i],w[i],finalpos[i]);
    }
    sort(P,P+n);
    int label[n];
    int nummeets = 0;
    for (int i = 0; i < n; i++){
        if (w[i] != w[0]){
            int rounds = (t/l);
            int left = t-rounds*l;
            nummeets += (rounds*2)%n;
            nummeets %= n;
            //printf("%d rounds\n",rounds);
            int dist = x[i]-x[0];
            if (w[0] == -1) dist = l-dist;
            //printf("dist is %d, timeleft %d\n",dist,left);
            if (left > (dist+l)/2) nummeets++;
            if (left > dist/2) nummeets++;
        }
    }
    //printf("0 meets %d times\n",nummeets);
    int k = ((w[0]*nummeets)%n + n) % n;
    int ans[n];
    ans[k] = finalpos[0];
    int anchor = finalpos[0];
    for (int i = 0; i < n; i++){
        if (P[i] == anchor){
            if (P[i+1] == anchor && w[0] == -1) continue;
            for (int j = 0; j < n; j++){
                //printf("%d -> %d\n",(k+j)%n,(i+j)%n);
                ans[(k+j)%n] = P[(i+j)%n];
            }
            break;
        }
    }
    for (int i =0 ; i < n; i++){
        printf("%d\n",ans[i]);
    }

}

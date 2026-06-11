#include <bits/stdc++.h>
using namespace std;

vector<int> finalpos;
long long initpos[100005];
long long finpos[100005];
bool clockwise[100005];
long long finalans[100005];
long long n,l,T;

int main(){
    scanf("%lld%lld%lld",&n,&l,&T);
    for (int x = 0; x<n; x++){
        int t;
        scanf("%lld%d",&initpos[x],&t);

        clockwise[x]= (t==1);

    }
    for (int x = 0; x<n; x++){
        finalpos.push_back(((initpos[x]+(clockwise[x]?T:(-T)))+T*l)%l);
        finpos[x] = finalpos[x];
    }
    sort(finalpos.begin(),finalpos.end());

    int finalnum = 0;
    for (int x = 1; x<n; x++){
        if (clockwise[0]&&!clockwise[x]) {
            finalnum += 2*(T/l);
            int dist1 = initpos[x]-initpos[0];
            int dist2 = dist1+l;
            if ((T%l)*2<=dist1) ;
            else if ((T%l)*2<=dist2) finalnum++;
            else finalnum += 2;

        }
        if (clockwise[x]&&!clockwise[0]){
            finalnum -= 2*(T/l);
            int dist1 = initpos[0]+l-initpos[x];
            int dist2 = dist1+l;
            //printf("d %d\n",dist2);
            if ((T%l)*2<dist1) ;
            else if ((T%l)*2<dist2) finalnum--;
            else finalnum -= 2;
        }
        finalnum%=n;
        //printf("%d\n",finalnum);
    }
    finalnum+=n;
    finalnum%=n;

    int t = lower_bound(finalpos.begin(),finalpos.end(),finpos[0])-finalpos.begin();
    finalans[finalnum] = finalpos[t];
    for (int x = 1; x<n; x++){
        finalans[(finalnum+x)%n] = finalpos[(t+x)%n];
    }
    for (int x = 0; x<n; x++){
        printf("%d\n",finalans[x]);
    }


}

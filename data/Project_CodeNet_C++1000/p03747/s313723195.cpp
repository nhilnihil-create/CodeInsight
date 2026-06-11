#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n,l,t;
int x[100005], w[100005];
int X[100005];
int pos[100005];
int ans[100005];
int main(){
    scanf("%d%d%d",&n,&l,&t);
    for (int i = 0; i < n; i++){
        scanf("%d%d",&x[i],&w[i]);
        if (w[i] == 1){
            X[i] = (x[i]+t)%l;
        }
        else{
            X[i] = ((x[i]-t)%l+l)%l;
        }
        pos[i] = X[i];
    }
    int curlabel = 0;
    for (int i = 1; i < n; i++){
        if (w[i] != w[0]){
            int ct = t/l;
            int add = 2*ct;
            int left = t-ct*l;
            int dist = x[i]-x[0];
            if (w[0] == 2) dist = l-dist;
            if (left > (dist+l)/2) add++;
            if (left > dist/2) add++;
            if (w[0] == 1) curlabel += add;
            else curlabel -= add;
        }
    }
    curlabel = (((curlabel%n)+n)%n);
    //printf("final label of ant 0 is %d, pos %d\n",curlabel,X[0]);
    sort(pos,pos+n);
    ans[curlabel] = X[0];
    int start = 0;
    while (pos[start] != X[0]) start++;
    if (start+1 < n && pos[start+1] == pos[start] && w[0] == 2) start++;
    for (int i = 1; i < n; i++){
        int id = (curlabel+i)%n;
        int id2 = (start+i)%n;
        ans[id] = pos[id2];
    }
    /*for (int i = 0; i < n; i++){
        printf("%d ",pos[i]);
    }
    printf("\n");*/
    for (int i =0;  i < n; i++){
        printf("%d\n",ans[i]);
    }
}


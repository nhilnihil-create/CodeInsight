#include<cstdio>
#include<algorithm>
struct Edge{
    int x,y;
    int c;
    Edge(){}
    Edge(int x,int y,int c):x(x),y(y),c(c){}
};
int a[305][305];
int d[305][305];
Edge e[90005];
int p[305];

int min(int a,int b){ return a>b?b:a; }

int find(int u){
    if(p[u]==u) return u;
    else return p[u] = find(p[u]);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){ 
            scanf("%d",&a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ok = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j]!=d[i][j]) ok = 0;
        }
    }
    if(!ok) printf("-1\n");
    else{
        int size = 0;
        for(int i = 1; i <= n; i++){
            p[i] = i;
            for(int j = i+1; j <= n; j++) e[++size] = Edge(i,j,a[i][j]);
        }
        std::sort(e+1,e+1+size,[&](Edge u,Edge v){ return u.c<v.c; });
        long long sum = 0;
        for(int i = 1; i <= size; i++){
            int x = e[i].x, y = e[i].y, w = e[i].c;
            int find = 0;
            for(int j = 1; j <= n; j++){
                if(j!=x && j!=y && d[x][j]+d[j][y]==w) find = 1;
            }
            if(!find){ 
                //printf("x = %d, y = %d: %d\n",x,y,w);
                sum += (long long)w;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}

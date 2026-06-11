#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int N,L,T,d,A[maxn];
int pre(int x) {return x == 1 ? N : x - 1;}
int nex(int x) {return x == N ? 1 : x + 1;}
int main(){
    #ifdef DMC
        freopen("DMC.txt","r",stdin);
    #endif

    cin >> N >> L >> T;
    for (int i = 1; i <= N; i++){
        int x,w; scanf("%d%d",&x,&w);
        if(w==1){
            int dt = T;
            if (L - x <= dt)
                dt -= (L - x),++d,x = 0;
            x += dt; d += dt / L; x %= L;
        }
        else{
            int dt = T;
            if (x + 1 <= dt)
                dt -= (x + 1),--d,x = L - 1;
            x -= dt; d -= dt / L; x %= L;
            if (x < 0) x += L;
        }
        A[i] = x; d %= N;
    }
    int pos = 1; d %= N;
    while (d < 0) pos = pre(pos),++d;
    while (d > 0) pos = nex(pos),--d;
    sort(A + 1,A + N + 1);
    for (int i = pos; i <= N; i++) printf("%d\n",A[i]);
    for (int i = 1; i < pos; i++) printf("%d\n",A[i]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long int N, L, T,p;
long long int X[100010];
long long int W[100010], Y[100010], Z[100010],S[100010], U[100010];
long long int A[100010], B[100010];
long long int a=0, b=0;
long long int pmod(long long int x, long long int a){
    if (x%a<0) return x%a+a;
    else return x%a;
}
long long int modL(long long int x){
    if(x%L==0) return L;
    else return pmod(x,L);
}
long long int locate_0(long long int t){
    if (W[0]==1){
        long long int i=0, d=0;
        while(d<=2*t){
            if (i%2==0){
                if (i==0) {
                    d+=modL(B[0]-A[0]);
                }
                else {
                    d+=modL(B[pmod(i/2,b)]-B[pmod(i/2-1,b)]);
                }
            }
            else{
                d+=modL(A[pmod((i-1)/2,a)]-A[pmod((i+1)/2,a)]);
            }
            i++;
            p=i;
        }
        if (i%2==0) return pmod(B[pmod((i-2)/2,b)]-t,L);
        else return pmod(A[pmod((i-1)/2,a)]+t,L);
    }
    else {
        long long int i=0, d=0;
        while(d<=2*t){
            if (i%2==0){
                if (i==0) {
                    d+=modL(B[0]-A[0]);
                }
                else {
                    d+=modL(A[pmod((i-2)/2,a)]-A[pmod(i/2,a)]);
                }
            }
            else{
                d+=modL(B[pmod((i+1)/2,b)]-B[pmod((i-1)/2,b)]);
            }
            i++;
            p=i;
        }
        if (i%2==0) return pmod(A[pmod((i-2)/2,a)]+t,L);
        else return pmod(B[pmod((i-1)/2,b)]-t,L);
    }
}
long long int f(long long int x){
    for (long long int i=0; i<N; i++){
        if (x==X[i]) return Y[i];
    }
    return 0;
}
int main() {
    cin >> N >> L >>T;
    for (long long int i=0; i<N; i++){
        cin >>X[i] >> W[i];
    }
    for (long long int i=0; i<N; i++){
        if(W[i]==2){
            B[b]=X[i];
            b++;
        }
    }
    for (long long int i=N; i>=1; i--){
        if (W[i%N]==1){
            A[a]=X[i%N];
            a++;
        }
    }
    
    
    int e=0;
    for (int i=0;i<N; i++){
        if (W[0]!=W[i]) e=1;
    }
    if (e){
        long long int s=0;
        long long int n=locate_0(L);
        for(int i=0;i<N;i++){
            if (X[i]==n){
                s=i;
                break;
            }
        }
        
        for (long long int i=0; i<N;i++){
            Y[i]=X[(i+s)%N];
        }
        
        int c=1;
       // Z[0]=X[0];
        for (int i=1; i<=N; i++){
            if (s*i%N==0){
                c=i;
                break;
            }
        }
        /* while(d!=X[0]){
            Z[c]=d;
            d=f(d);
            c++;
        }*/
        
        
        long long int f=(T/L);
        long long int g=c-f%c;
        long long int h=g%c;
        long long int k=s*h;
        long long int u=k%N;
        
        
        for (long long int i=0; i<N; i++){
            if (W[i]==1) S[i]=(X[i]+T)%L;
            else S[i]=pmod((X[i]-T),L);
        }
        sort(S, S+N);
        
        long long int v=0;
        long long int m=locate_0(T%L);
        for (int i=0;i<N;i++){
            if (S[i]==m) {
                v=i;
                break;
            }
        }
        if (S[(v+1)%N]==S[v]&&((W[0]==1&&p%2==1)||(W[0]==2&&p%2==0))) v++;
        for (long long int i=0; i<N; i++){
            U[i]=S[pmod(v-u+i,N)];
            cout << U[i] <<endl;
        }
    }
    else {
        if (W[0]==1){
            for (int i=0;i<N;i++){
                U[i]=(X[i]+T)%L;
                cout << U[i] <<endl;
            }
        }
        else {
            for (int i=0;i<N;i++){
                U[i]=pmod((X[i]-T),L);
                cout << U[i] <<endl;
            }
        }
    }
}

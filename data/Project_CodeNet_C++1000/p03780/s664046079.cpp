#include <bits/stdc++.h>
#define MAX_N 5000
#define MAX_K 5000
using namespace std;
int dpl[MAX_N+1][MAX_K];
int dpr[MAX_N+1][MAX_K];
int a[MAX_N];
int N,K;
int main(void){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    dpl[0][0]=1;
    dpr[N][0]=1;
    for(int y=1;y<K;y++){
        dpl[0][y]=0;
        dpr[N][y]=0;
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<K;y++){
            if (dpl[x][y]==1){
                dpl[x+1][y]=1;
                if (y+a[x]<K){
                    dpl[x+1][y+a[x]]=1;
                }
            }
            if (dpr[N-x][y]==1){
                dpr[N-1-x][y]=1;
                if(y+a[N-1-x]<K){
                    dpr[N-1-x][y+a[N-1-x]]=1;
                }
            }
        }
    }
    int ans=0;
    for(int x=0;x<N;x++){
        int Sx[MAX_K+1];
        for(int i=0;i<K;i++){
            Sx[i+1]=Sx[i]+dpl[x][i];
        }
        int flag=0;
        for(int y=0;y<K;y++){
            if(dpr[x+1][y]==1){
                int high=K-y;
                int low=K-y-a[x];
                if (low<0){
                    low=0;
                }
                if (Sx[high]-Sx[low]>0){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

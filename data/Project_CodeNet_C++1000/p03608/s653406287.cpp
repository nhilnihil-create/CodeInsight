#include<iostream>
#include<algorithm>
using namespace std;

const long long INF=100000000;

int main(){
    //input
    long long N,M,R;
    cin >> N >> M >> R;
    long long r[R];
    long long i,j,k;
    for(i=0; i<R; i++){
        cin >> r[i];
    }
    long long a[N+1][N+1];
    for(i=0; i<=N; i++){
        for(j=0; j<=N; j++){
            a[i][j]=INF;
        }
    }
    for(i=1; i<=N; i++){
        a[i][i]=0;
    }
    long long A,B,C;
    for(i=1; i<=M; i++){
        cin >> A >> B >> C;
        a[A][B]=a[B][A]=C;
    }

    //calc

    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            for(k=1; k<=N; k++){
                a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
            }
        }
    }
    long long ans=INF, val;
    sort(r,r+R);
    do{
        val=0;
        for(i=0; i<R-1; i++){
            val+=a[r[i]][r[i+1]];
        }
        ans=min(ans,val);
    }while(next_permutation(r,r+R));

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}
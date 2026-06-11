#include<bits/stdc++.h>
using namespace std;

long long a_min[2000][2000];

int main(){
    //input
    long long N;
    cin >> N;
    long long x;
    cin >> x;
    long long a[2*N], a_sub;
    long long i,j;
    for(i=0; i<N; i++){
        cin >> a_sub;
        a[i]=a_sub;
        a[i+N]=a_sub;
    }

    //calc
    for(i=0; i<N; i++){
        a_min[i][0]=a[i+N];
    }
    for(i=0; i<N; i++){
        for(j=1; j<N; j++){
            a_min[i][j]=min(a_min[i][j-1],a[i+N-j]);
        }
    }
    long long ans=10000000000000000;
    long long val;
    for(j=0; j<N; j++){
        val=j*x;
        for(i=0; i<N; i++){
            val+=a_min[i][j];
        }
        ans=min(ans,val);
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}
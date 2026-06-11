#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define ll long long
#define MODD 1000000007
#define Inf 123372036854775806ll
using namespace std;

int X[111111];
int Y[111111];
int M[111111][18];
int INVPOW[111111];

// 1,2,3
// 1,0,3


int RMQ(int i, int j) {
    if (i > j)
        return 0;
    int k=INVPOW[j-i+1];
    return min(X[M[i][k]],X[M[j-(1<<k)+1][k]]);
}


int main() {
    int N;
    cin>>N;
    
    //vector<int> X(N);
    X[0]=-1;
    for(int i=1;i<=N;i++) {
        cin>>X[i];
        X[i]-=2*i+1;
    }
    
    for(int i=1;i<111111;i++) {
        int k=0;
        while((1<<(k+1))<=i) {
            k++;
        }
        INVPOW[i]=k;
    }
    
    for (int i = 0; i < N; i++)
        M[i][0] = i;
    for (int j = 1; (1 << j) <= N; j++) {
        for (int i = 0; i + (1 << j) - 1 < N; i++) {
            if (X[M[i][j - 1]] <= X[M[i + (1 << (j - 1))][j - 1]])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }
    }
    
    
    ll prod = 1;
    Y[0]=0;
    int prev_ct=0;
    for(int i=1;i<=N;i++) {
        int numsp=0;
        int minn=-1;
        
        int low=1;
        int high=i;
        while(low < high) {
            int mid=(low+high)/2;
            if (RMQ(mid,i-1) >= -2*mid) {
                high=mid;
            } else {
                low=mid+1;
            }
        }
        
        /*
        
        for(int j=1;j<=i;j++) {
            
            if (RMQ(j,i-1) >= -2*j) {
                minn=j;
                break;
            }
            
            // X[j] to X[i-1]
            // X[j] >= 1
            // X[j+1] >= 3
            // X[i-1] >= 2*(i-1-j)+1
            
            // X[k] >= 2*(k-j)+1
            // X[k]-2*k-1 >= -2*j
            bool ok;
            if (X[i-1] < 2*(i-1-j)+1)
                ok=false;
            else
                ok=true;
            
            
            for(int k=j;k<=i-1;k++) {
                //
            }
            // 1,3,...
            bool ok=true;
            // minn(Xt[j]..Xt[i-1]) >= -2*j
            for(int k=j;k<=i-1;k++) {
                if (X[k]-2*k-1<-2*j) {
                    ok=false;
                    break;
                }
            }
            
            if (ok)
            {
                minn=j;
                break;
            }
             
        }
             */
    

        prod = (prod * (ll)(i-low+1))%MODD;
    }
    
    cout << prod%MODD << endl;
    //cout << Solve(X) << endl;
    
    
}
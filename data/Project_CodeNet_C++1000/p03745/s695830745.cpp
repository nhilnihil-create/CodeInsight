#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<LL> A(N,0);
    REP(i,N)cin>>A[i];

    long long ans = 0;
    
    int mode = 0; //0:不定, 1:非減少, 2:非増加
    FOR(i,1,N){
        LL pre_val = A[i-1];
        LL val = A[i];

        if(mode==0){
            if(pre_val < val){
                mode = 1;
            }else if (pre_val > val){
                mode = 2;
            }
        }else if(mode==1){
            if(pre_val > val){
                ans+=1;mode=0;
            }
        }else if(mode==2){
            if(pre_val < val){
                ans+=1;mode=0;
            }
        }

    }

    cout << ans + 1 << endl;
    return 0;
}
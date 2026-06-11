#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL INF=1e18;

int main(){
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        int sum=(i*(i+1))/2;
        if(N<=sum){
            for(int j=1;j<=i;j++){
                if(j==sum-N) continue;
                cout << j << endl;
            }
            return 0;
        }
    }
    return 0;
}
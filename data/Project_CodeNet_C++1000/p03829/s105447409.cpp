#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long mod = 1e9+7;
int main(void){
    long long N,A,B;
    cin >> N >> A >> B;
    long long X[N];
    rep(i,N)cin>>X[i];
    
    long long ans = 0;
    for(int i=0;i+1<N;i++){
        long long  d = (X[i+1] - X[i]) * A;
        if(d < B){
            ans+=d;
        }
        else{
            ans+= B;
        }
    }
    cout << ans << endl;
}

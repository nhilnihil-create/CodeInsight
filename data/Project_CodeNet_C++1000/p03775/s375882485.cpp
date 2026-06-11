#include <iostream>
#include <algorithm>
using namespace std;
int F(long long A,long long B){
    long long X = max(A,B);
    int res = 0;
    while(X > 0){
        X /= 10;
        res++;
    }
    return res;
}
int main(void){
    long long N;
    cin >> N;
    int ans = F(1,N);
    for(long long i=2;i*i<=N;i++){
        if(N % i == 0){
            ans = min(ans,F(i,N/i));
        }
    }
    cout << ans << endl;
}

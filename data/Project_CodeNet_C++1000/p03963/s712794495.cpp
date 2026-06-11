#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int main(void){
    int N,K;
    cin >> N >> K;
    long long ans = 1;
    for(int i=0;i<N;i++){
        if(i == 0){
            ans *= K;
            K--;
        }
        else{
            ans *= K;
        }
    }
    cout << ans << endl;
}

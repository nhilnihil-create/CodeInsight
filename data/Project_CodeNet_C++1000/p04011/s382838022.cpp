#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(void){
    int N,K,X,Y;
    cin >> N >> K >> X >> Y;
    int n=1;
    int ans = 0;
    while(n <= N){
        if(n <= K){
            ans += X;
        }
        else{
            ans += Y;
        }
        n++;
    }
    cout << ans << endl;
}

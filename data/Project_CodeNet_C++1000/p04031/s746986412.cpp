#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
int cost(int x,int y){
    return (x-y) * (x-y);
}
int main(void){
    int N;
    cin >> N;
    int a[N];
    rep(i,N){
        cin >> a[i];
    }
    int ans = 1e9;
    for(int i=-100;i<=100;i++){
        int sum = 0;
        for(int j=0;j<N;j++){
            sum += cost(i,a[j]);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}

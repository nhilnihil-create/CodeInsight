#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long ans = 10000000000000;
    for(int i=0; i<pow(2,N); i++){
        int max = a[0];
        long t = 0;
        int cnt = 1;
        for(int j=1; j<N; j++){
            if(a[j] > max){
                cnt++;
                max = a[j];
                continue;
            }
            if((i >> j) & 1){
                t += max - a[j] + 1;     
                max = max + 1;
                cnt++;
            }
        }
        if(cnt <K) continue;
        if(t <= ans) ans = t;
    }

    cout << ans << endl;

    return 0;
}
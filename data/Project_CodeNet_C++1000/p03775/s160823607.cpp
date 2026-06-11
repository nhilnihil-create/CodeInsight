#include <bits/stdc++.h>
using namespace std;

int digit(long long k){
    int cnt = 0;
    while(k){
        cnt++;
        k /= 10;
    }
    return cnt;
}

int main(){
    long long int n;
    cin >> n;
    int ans = 100;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            ans = min(ans,max(digit(i),digit(n/i)));
        }
    }
    cout << ans << endl;
    return 0;
}




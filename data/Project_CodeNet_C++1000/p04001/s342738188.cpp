#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    long S, j = 0, ans = 0;
    cin >> S;
    while(pow(10, j) <= S) j++;
    j--;
    for(long bit = 0; bit < (1<<j); bit++){
        long A = S, k = -1;
        for(long i = 0; i < j; i++){
            if((1<<i) & bit){
                ans += A % (long)(pow(10, i - k));
                A = A / (long)(pow(10, i - k));
                k = i;
            }
        }
        ans += A;
    }
    cout << ans << endl;
    return 0;
}
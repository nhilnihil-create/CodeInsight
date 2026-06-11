#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int64_t N;
    cin >> N;
    int i;
    int B,size;
    int ans = 100000;
    int F = (int)floor(sqrt(N));

    for(i=1;i<=F;i++){
        if(N % i == 0){
            B = N / i;
            string B_string = to_string(B);
            size = B_string.size();
            ans = min(ans,size);
        }
    }
    cout << ans << endl;
}
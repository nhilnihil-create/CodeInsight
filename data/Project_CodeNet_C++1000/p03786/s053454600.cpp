#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N; cin >> N;
    vector<long long > a(N);
    for (int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long sum = 0;
    int ans = 0;
    for (int i=0; i<N; i++){
        if (2 * sum < a[i]){
            ans = i;
        }
        sum += a[i];
    }

    cout << N - ans  << endl;
    
}
    

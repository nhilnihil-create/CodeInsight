#include <bits/stdc++.h>
using namespace std;

int hoge(int n){
    int sum = 0;
    while (n) {
        if (n % 2 == 0) {
            sum++;
        }
        n /=2;
    }
    return sum;
}

int main() 
{
    int N;
    cin >> N;
    
    int ans = 0;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (sum < hoge(i)) {
            sum = hoge(i);
            ans = i;
        }
    }
    if (ans == 0) {
        cout << N << endl;
    }else{
        cout << ans << endl;
    }
}
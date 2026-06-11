#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int K, S;
    cin >> K >> S;
    int ans = 0;
    for(int i = 0; i <= K; i++){
        for(int j = 0; j <= K; j++){
            if(i + j <= S && i + j >= S - K){
                ans += 1;
            }
        }
    }
    cout << ans;
}
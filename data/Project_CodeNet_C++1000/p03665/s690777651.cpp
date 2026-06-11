#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int arr[55];
ll memo[5000][55];
int totalsum = 0;
int n, p;
//a = total sum so far b = index
ll dp (int a, int b){
    if (b > n){
        if (a%2 == p)
            return 1;
        return 0;
    }
    if (memo[a][b] != -1)
      return memo[a][b]; 
    return memo [a][b] = dp(a+arr[b],b+1) + dp(a,b+1);
}

int main()
{
    cin >> n >> p;
    
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    memset (memo, -1, sizeof(memo));
    cout << dp(0,1) << endl;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
 
int main(void){
    int n;
    cin >> n;
    long long int num[n];
    long long int sum[n];
    long long int ans = 10000000000000;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(i==0) sum[i]=num[i];
        else sum[i]=sum[i-1]+num[i];
    }
    for(int i = 0; i < n-1; i++)
        ans = min(ans, abs(sum[i]-(sum[n-1]-sum[i])));

    cout << ans << endl;
    return 0;
}
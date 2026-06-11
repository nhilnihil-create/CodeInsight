#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
//わからん
int main() {
    int n;
    cin >> n;
    long long a[100001];
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans1 = 0;
    long long ans2 = 0;

    for(int i = 0; i < n; i++){
        sum1 += a[i];
        if(i % 2 == 0 && sum1 <= 0){
            ans1 += (1 - sum1); 
            sum1 += (1 - sum1);
            if(sum1 == 0) {
                sum1++;
                ans1++;
            }
        }

        else if(i % 2 == 1 && sum1 >= 0){
            ans1 += (sum1 + 1);
            sum1 -= (1 + sum1);
            if(sum1 == 0) {
                sum1--;
                ans1++;
            }
        }
    }


    for(int i = 0; i < n; i++){
        sum2 += a[i];

        if(i % 2 == 0 && sum2 >= 0){
            ans2 += (sum2 + 1); 
            sum2 -= (1 + sum2);
            if(sum2 == 0) {
                sum2--;
                ans2++;
            }
        }
        else if(i % 2 == 1 && sum2 <= 0){
            ans2 += (1 - sum2);
            sum2 += (1 - sum2);
            if(sum2 == 0) {
                sum2++;
                ans2++;
            }
        }
    }

    if(sum2 == 0) ans2++;
    
    if(ans1 >= ans2) cout << ans2 << endl;
    else cout << ans1 << endl;

    return 0;
}
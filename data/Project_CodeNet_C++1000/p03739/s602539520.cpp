#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // posi -> negative -> posi .... の場合に関して,操作回数を調べる
    long long cost1 = 0;
    long long sum1 = 0;
    for (int i = 0; i < n; i++){
        
        sum1 += a[i];
        
        if (i % 2 == 0 && sum1 > 0) continue;
        else if (i % 2 == 0 && sum1 <= 0){
            cost1 += abs(sum1) + 1;
            sum1 = 1;
        }
        else if (i % 2 == 1 && sum1 >= 0){
            cost1 += abs(sum1) + 1;
            sum1 = -1;
        }
        else{
            continue;
        } 
    }
    
     // negative -> positive -> negative .... の場合に関して,操作回数を調べる
    long long cost2 = 0;
    long long sum2 = 0;
    for (int i = 0; i < n; i++){
        
        sum2 += a[i];
        
        if (i % 2 == 0 && sum2 >= 0){
            cost2 += abs(sum2) + 1;
            sum2 = -1;
        }
        else if (i % 2 == 0 && sum2 < 0){
           continue;
        }
        else if (i % 2 == 1 && sum2 > 0){
           continue;
        }
        else{
            cost2 += abs(sum2) + 1;
            sum2 = 1;
        } 
    }
    
    long long ans = min(cost1, cost2);
    cout << ans << endl;
}

#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[100001];
    for(int i = 0; i < n; i++) cin >> a[i];
    long long sum1 = 0;
    long long p1 = 0;
    long long sum2 = 0;
    long long p2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += a[i];
        if(i%2 == 0 && sum1 <= 0){
            p1 += (1 - sum1);
            sum1 += (1 - sum1);
        }

        else if(i%2 == 1 && sum1 >= 0){
            p1 += (1 + sum1);
            sum1 -= (1 + sum1);
        }
    }
    for(int i = 0; i < n; i++){
        sum2 += a[i];
        if(i%2 == 1 && sum2 <= 0){
            p2 += (1 - sum2);
            sum2 += (1 - sum2);
        }

        else if(i%2 == 0 && sum2 >= 0){
            p2 += (1 + sum2);
            sum2 -= (1 + sum2);
        }
    }
    
    long long p = (p1 < p2) ? p1 : p2;
    cout << p << endl; 
    return 0;
}

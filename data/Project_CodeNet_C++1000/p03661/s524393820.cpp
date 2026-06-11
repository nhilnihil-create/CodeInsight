/*
    アリナ・グレイはかわいい
*/

#include<bits/stdc++.h>
using namespace std;
#define itn int
#define endl "\n"

int main(void){
    int n;
    cin >> n;
    long long int a[n],num[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    
    num[0] = a[0];
    for(int i = 1;i < n;i++)num[i] = num[i-1] + a[i];
    
    long long int sum = abs(num[0] - (num[n-1] - num[0]));
    for(int i = 1;i < n-1;i++)sum = min(sum,abs(num[i]-(num[n-1]-num[i])));
    
    cout << sum << endl;
}

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    int avg = ceil(float(sum)/n);
    int avg2 = floor(float(sum)/n);
    int cost = 0;
    int cost2 = 0;
    for(int i = 0; i < n; i++) {
        cost += (a[i]-avg)*(a[i]-avg);
        cost2 += (a[i]-avg2)*(a[i]-avg2);
    }
    cout<<min(cost,cost2);
    return 0;
}
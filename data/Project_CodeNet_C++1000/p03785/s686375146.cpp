#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, c, k, arr[100005], range, capacity=0, count=0;
    cin >> n >> c >> k;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    range=arr[1]+k;
    capacity++;
    count++;
    for(int i=2;i<=n;i++){
        if(arr[i]<=range && capacity<c) {
            capacity++;
        }
        else{
            range=arr[i]+k;
            capacity=1;
            count++;
        }
    }
    cout <<count;
    return 0;
}
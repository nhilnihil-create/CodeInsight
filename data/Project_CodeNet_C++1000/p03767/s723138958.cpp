#include <iostream>
#include <algorithm>
using namespace std;
bool descending(int a, int b){
    if(a>b) return true;
    else return false;
}
#define ll long long
int main(){
    int n, arr[300005];
    cin >> n;
    ll sum=0;
    for(int i=1; i<=3*n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+3*n+1, descending);
    for(int i=2; i<=2*n; i+=2){
        sum+=arr[i];
    }
    cout << sum << endl;
    return 0;
}
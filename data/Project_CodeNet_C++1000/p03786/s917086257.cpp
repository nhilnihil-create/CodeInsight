#include<iostream>
#include<algorithm>
using namespace std;
int n, i;
long long sum;
int v[100005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum += v[i];
    }
    sort(v + 1, v + n + 1);
    for(i = n - 1; i >= 1; i--){
        sum -= v[i + 1];
        if(2 * sum < v[i + 1]){
            break;
        }
    }
    cout<< n - i;
}

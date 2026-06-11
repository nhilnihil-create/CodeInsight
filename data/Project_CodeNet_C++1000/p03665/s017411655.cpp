#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
int n, p, value[105];
ll memo[55][5005];
ll calculate(int i, ll sum){
    if(memo[i][sum]!=-1)return memo[i][sum];
    if(i>n){
        if(sum%2== p)return 1;
        else return 0;
    }
    ll t = calculate(i+1, sum+value[i]);
    ll nt = calculate(i+1, sum);
    memo[i][sum]=t+nt;
    return memo[i][sum];
}
int main(){
    memset(memo, -1, sizeof(memo));
    cin >> n >> p;
    for(int i=1; i<=n; i++){
        cin >> value[i];
    }
    cout << calculate(1, 0)<< endl;
    return 0;
}

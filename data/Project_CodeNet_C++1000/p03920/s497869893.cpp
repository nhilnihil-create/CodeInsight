#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int N,maxi,sum = 0;
    cin >> N;
    for(int i = 1;i <= N;i++){
        sum += i;
        maxi = i;
        if(sum >= N)break;
    }    
    for(int i = maxi;N > 0 && i >= 0;i--){
        if(N < i)continue;
        cout << i << endl;
        N -= i;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,P;
    cin >> N >> P;
    int num[2] ={};
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        num[a%2]++;
    }
    if(P==1 && num[1] == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans =1;
    for(int i=0;i<num[0];i++){
        ans *=2;
    }
    for(int i=0;i<(num[1]-1);i++){
        ans *= 2;
    }
    cout << ans << endl;


    return 0;
}
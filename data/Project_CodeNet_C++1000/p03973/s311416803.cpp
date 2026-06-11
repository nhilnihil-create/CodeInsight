#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N;
ll A[100010];
ll ans;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ans += A[0] - 1;
    int me = 2, mo = 3; 
    for(int i = 1; i < N; i++){
        if(me < mo && A[i] == me){
            me += 2;
            continue;
        }
        if(me > mo && A[i] == mo){
            mo += 2;
            continue;
        }
        int m = min(me, mo);
        ans += A[i] / m;
        if(A[i] % m == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}
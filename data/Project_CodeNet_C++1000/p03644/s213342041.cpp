#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans = 1;
    while(1){
        if(ans * 2 <= N){
            ans *= 2;
        }
        else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
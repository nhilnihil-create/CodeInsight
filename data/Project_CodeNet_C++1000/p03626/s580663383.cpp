#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    string S[2];
    cin >> S[0];
    cin >> S[1];

    ll ans = 1;
    int before = -1;
    for(int i=0; i<N; i++){
        if(before == -1){
            if(S[0][i+1] == S[0][i]){
                ans = ans * 6;
                before = 0;
                i++;
            }else{
                ans = ans * 3;
                before = 1;
            }
            continue;
        }
        if(i == N-1){
            if(before == 1) ans = (ans*2)%MOD;
            continue;
        }
        if(before == 0){
            if(S[0][i] == S[0][i+1]){
                ans = (ans * 3)%MOD;
                i++;
                before = 0;
            }else{
                ans = ans;
                before = 1;
            }
        }else{
            if(S[0][i] == S[0][i+1]){
                ans = (ans * 2)%MOD;
                i++;
                before = 0;
            }else{
                ans = (ans * 2)%MOD;
                before = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

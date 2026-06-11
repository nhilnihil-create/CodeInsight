#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    map<int, int> m;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(m.count(a) == 0) m[a] = 1;
        else m[a]++;
    }

    bool fl = true;
    ll ans = 1;
    if(N % 2 != 0){
        if(m[0] != 1) fl = false;
        for(int i=2; i<N; i=i+2){
            if(m[i] != 2) fl = false;
            ans = ans * 2;
            ans = ans % MOD;
        }
    }else{
        for(int i=1; i<N; i=i+2){
            if(m[i] != 2) fl = false;
            ans = ans * 2;
            ans = ans % MOD;
        }
    }

    if(!fl) cout << 0 << endl;
    else cout << ans << endl;

    return 0;
}

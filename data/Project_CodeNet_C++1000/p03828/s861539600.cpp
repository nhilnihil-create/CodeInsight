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
    for(int i=2; i<=N; i++){
        map<int, int> mt;
        int t = i;
        for(int j=2; j<=t; j++){
            if(t % j != 0) continue;
            int cnt = 0;
            while(t % j == 0){
                cnt++;
                t = t / j;
            }
            mt[j] = cnt;
            if(t == 1) break;
        }
        for(auto f : mt){
            if(m.count(f.first) == 0)m[f.first] = f.second;
            else m[f.first] += f.second;
        }
    }

    ll ans = 1;
    for(auto n : m){
        ans = ans * (n.second+1);
        ans = ans % MOD;
    }

    cout << ans << endl;

    return 0;
}

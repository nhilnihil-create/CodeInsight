#include <iostream>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N,K;
    cin >> N >> K;
    map<int, long long> mp;
    for(int i = 0; i < N; ++i){
        int a, b; cin >> a >> b;
        mp[a] += b;
    }
    
    for(auto it = mp.begin(); it != mp.end(); ++it){
        if(K - it->second <= 0){
            cout << it->first << endl;
            break;
        }
        K -= it->second;
    }
    return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N, M;  cin >> N >> M;
    map<int, int> mp;
    for(int i=0; i<M; i++){
        int a, b;  cin >> a >> b;
        a--;  b--;
        mp[a]++;
        mp[b]++;
    }

    for(auto p : mp){
        if(p.second%2 == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

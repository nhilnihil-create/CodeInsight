#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N , M;
    cin >> N >> M;
    
    map<int,int> mp;
    
    for(int i = 0; i < M; i++){
        ll tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        mp[tmp1]++;
        mp[tmp2]++;
    }

    for(int i = 1; i <= N; i++){
        if(mp[i] % 2 != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;

}


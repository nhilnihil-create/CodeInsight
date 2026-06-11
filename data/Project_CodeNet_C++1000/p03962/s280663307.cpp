#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define loop(i, n) for(int i = 0;i < n;i++)

int main(void){

    
    map<int, int> mp;
    loop(i, 3){
        int a; cin >> a;
        mp[a]++;
    }

    cout << mp.size() << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <functional>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 0;i < n;i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    if((n - mp.size()) % 2 == 0)cout << mp.size() << endl;
    else cout << mp.size() - 1 << endl;
}

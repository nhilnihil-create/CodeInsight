#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
    map<int, int> mp;
    int N; cin >> N;
    rep(i,N){ int s; cin >> s; mp[s]++;}
    int counter = 0;
    for (auto itr : mp){
//      cout << itr.first << "-" << itr.second << endl;
      if (itr.second%2 == 1) counter++;
    }
    cout << counter << endl;
    return 0;
}
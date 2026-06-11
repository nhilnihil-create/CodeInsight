#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   string s;cin >>s;
   vector<int>direction(4,-1);
   char x[4]={'N','S','W','E'};
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i] == x[j])direction[j] += 2;
        }
    }
    if(direction[0]*direction[1]<0||direction[2]*direction[3]<0)puts("No");
    else puts("Yes");
   return 0;
}


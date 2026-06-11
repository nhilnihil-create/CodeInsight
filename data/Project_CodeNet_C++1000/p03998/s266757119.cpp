#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
   vector<string> s(3);
   rep(i,3) cin >> s[i];
   int i = 0;
   while(1) {
       if(s[i].size()==0) {
           cout << char(i+'A') << endl;
           return 0;
        }
        char t = s[i][0];
        s[i].erase(s[i].begin());
        i = t - 'a';
   }
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

/*
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/
typedef long long ll ;
const ll mk = 250055;
const ll logn  = 29;
const ll mod = 1e9 + 7;

#define endl             "\n"
#define IOS              ios::sync_with_stdio(0); cin.tie(0);
#define fi               first
#define se               second
#define pii              pair<ll,ll>
#define mp               make_pair
#define pq               priority_queue<int, std::vector<int>, std::greater<int> >
#define rep(i, n)        for(int i = 0 ; i < n ; i++)
#define pb               push_back

string s, t;
int q;
  
/*

the remainder of it for 3 never change 
111 -> 0
222 -> 0
1   -> 22
2   -> 11

*/
int main() {
  IOS;
  
  cin >> s >> t >> q;
  
  vector<int> x(s.size() + 1), y(t.size() + 1);
  
  for (int i = 1; i <= s.size(); i++) {
    x[i] = s[i -1] -'A' +1;
    x[i] +=x[i-1]; 
  }
  for (int i = 1; i <= t.size(); i++) {
    y[i] = t[i -1]-'A' +1;
    y[i] += y[i-1];
  }
  
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((x[b] - x[a -1]) % 3 == (y[d]-y[c -1]) % 3) cout << "YES" << endl;
    else cout << "NO" <<endl;
  }
}
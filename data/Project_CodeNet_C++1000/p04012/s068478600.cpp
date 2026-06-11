///////////////////////////////////////////////////////////////////////////
// /*Dis = size of the program || TLE. */
/*
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
*/
// #pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops") /* D = Too many loops */

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
#define pi acos(-1.0)
#define MAX 10000001
//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */

    string str;
    cin >> str;
    int even{}, odd{};

    map<int, int> map;
    for(int i = 0; i<str.size(); i++){
        if(map.count(str[i]) == 0 ){
            map.insert(make_pair(str[i], 1));
        }
        else{
            map[str[i]]++;
        }
    }

    auto itr = map.begin();
    auto itr2 = map.end();

    for(; itr != itr2; itr++){
        if(itr -> second %2 == 0){
        even = 1;
        }
        else{
            even = 0;
            break;
        }
    }

    if(even == 1){
        cout << "Yes" << endl;
    }
    else if(even == 0){
        cout << "No" << endl;
    }
  /* MAIN Code ENDS here: */
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define     endl               '\n'
#define     fast_io            ios::sync_with_stdio(false); cin.tie(0);
#define     all(x)             begin(x), end(x)
#define     debug(x)           cerr <<"Line "<< __LINE__ <<" : "<< #x " = "<< x <<endl;
 
template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<"("<<t.first<<", "<<t.second<<")"; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }




int main(int argc, char** argv) {
    //fast_io
    

    int n, oc = 0;
    cin >> n;
    
    
    for(int i = 0, a; i < n; ++i) {
	cin >> a;
	if(a&1) ++oc;
    }
    
    if(n == 1 || !(oc&1)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
    return 0;
}

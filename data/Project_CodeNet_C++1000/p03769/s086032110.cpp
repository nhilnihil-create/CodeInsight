#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)

int main(){
    ll N;
    cin >> N;

    vi ans; 

    vi seq;
    while (N > 0) {
        if (N%2 == 1) {
            N = (N-1)/2;
            seq.push_back(1);
        } else {
            N = N-1;
            seq.push_back(0);
        }
    }
    reverse(seq.begin(), seq.end());

    vi perm;
    int extra = 0;
    int cur = 1;
    for (int s : seq) {
        if (s == 0) {
            // x+1
            perm.push_back(cur);
            cur++;
        } else {
            //2x+1
            perm.insert(perm.begin(), cur);
            cur++;
        }
    }

    for (int i=cur-1;i>0;i--) ans.push_back(i);
    for (int x : perm) ans.push_back(x);

    // for (int i=1;i<=extra;i++) {
    //     ans.push_back(B+i);
    //     ans.push_back(B+i);
    // }

    

    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;

    return 0;
}

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

ll nsum(ll n) {
    return (n*(n+1))/2;
}

int main(){
    int N;
    cin >> N;

    vll A(N);
    for (int i=0;i<N;i++) cin >> A[i];

    ll ns = nsum(N);
    ll total = 0;
    for (ll a : A) total += a;

    if (total % ns != 0) {
        cout << "NO" << endl;
        return 0;
    }

    ll M = total / ns;

    vll diffs(N);
    diffs[0] = A[0] - A[N-1];
    for (int i=1;i<N;i++) {
        diffs[i] = A[i] - A[i-1];
    }

    for (int i=0;i<N;i++) {
        if ((M-diffs[i]) % N != 0 || (M - diffs[i]) < 0) {
            cout << "NO" << endl;
            return 0;
        } 
    }

    cout << "YES" << endl;
}

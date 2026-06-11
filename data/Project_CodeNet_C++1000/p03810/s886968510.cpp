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

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool solve(int N, vll& A) {
    ll S = 0;
    for (ll a : A) S += a;

    if (N % 2 == 0) {
        if (S % 2 == 0) return false;
        else return true;
    } else {
        int num_odd = 0;
        int sum_odd = 0;
        for (ll a : A) {
            num_odd += (a % 2);
            if (a%2 == 1) sum_odd += a;  
        } 

        if (S % 2 == 0) return true;
        else if (num_odd > 1) return false;
        else {
            if (sum_odd == 1) return false;

            vll B(A);
            for (int i=0;i<N;i++){
                if (B[i] % 2 == 1) B[i]--;
            } 

            ll g = B[0];
            for (int i=1;i<N;i++) g = gcd(g, B[i]);

            for (int i=0;i<N;i++) {
                B[i]/=g;
            }
            return !solve(N, B);
        }

    }
}

int main(){
    int N;
    cin >> N;

    vll A(N);

    for (int i=0;i<N;i++) cin >> A[i];
    
    if (N == 1) {
        cout << "Second" << endl;
        return 0;
    } 

    if (solve(N, A)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;

}

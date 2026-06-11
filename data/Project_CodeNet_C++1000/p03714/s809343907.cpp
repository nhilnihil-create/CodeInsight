#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
typedef long long ll;

using reverse_priority_queue = priority_queue<ll, vector<ll>, std::greater<ll>>;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    for(int i = 0; i < 3 * n; ++i){
        cin >> a.at(i);
    }

    vector<ll> lmax(3 * n, 0);
    {
        reverse_priority_queue qsum;
        ll total = 0;
        for(int i = 0; i < 3 * n; ++i){
            if(qsum.size() < n){
                total += a.at(i);
                qsum.push(a.at(i));
            }else if(qsum.top() < a.at(i)){
                ll tmp = qsum.top();
                qsum.pop();
                qsum.push(a.at(i));
                total += a.at(i) - tmp;
            }
            lmax.at(i) = total;
        }
    }

    vector<ll> rmin(3 * n, 0);
    {
        priority_queue<ll> qsum;
        ll total = 0;
        for(int i = 3 * n - 1; i >= 0; --i){
            if(qsum.size() < n){
                total += a.at(i);
                qsum.push(a.at(i));
            }else if(qsum.top() > a.at(i)){
                    ll tmp = qsum.top();
                    qsum.pop();
                    qsum.push(a.at(i));
                    total += a.at(i) - tmp;
            }
            rmin.at(i) = total;
        }
    }

    ll ans = numeric_limits<ll>::min();
    for(int i = n - 1; i < 2 * n; ++i){
        ans = max(ans, lmax.at(i) - rmin.at(i + 1));
    }
    cout << ans << endl;
    return 0;
}

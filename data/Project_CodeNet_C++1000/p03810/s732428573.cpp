#include <bits/stdc++.h>
using namespace std;
using namespace placeholders;
using ll = long long;
 
ll gcd(const ll a, const ll b){
    return a == 0 ? b : gcd(b%a, a); }
 
bool first_wins(vector<ll>& v){
    v.erase(remove(begin(v), end(v), 1), end(v));
    if(v.size() == 1) return (v[0]+1)%2;
    static auto is_odd = [](const ll x){ return x%2 == 1; };
    const ll nr_odd = count_if(begin(v), end(v), is_odd);
    if((nr_odd + v.size())%2) return true;
    else if(nr_odd != 1) return false;
    else if(*find_if(begin(v), end(v), is_odd) == 1) return false;
    else{
        --*find_if(begin(v), end(v), is_odd);
        const ll full_gcd = accumulate(begin(v), end(v), v.front(), &gcd);
        transform(begin(v), end(v), begin(v), bind(divides<ll>(), _1, full_gcd));
        return !first_wins(v); } }
 
int main(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto& x : v) cin >> x;
    cout << (first_wins(v) ? "First" : "Second") << endl;
    return 0; }

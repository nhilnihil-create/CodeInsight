#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

ll get_path_len(ll x, ll y){
    if(x < y){swap(x, y);}
    ll ret = (x / y) * 2 * y;
    if(x%y == 0){
        ret -= y;
    }
    else{
        ret += get_path_len(y, x%y);
    }
    return ret;
}

int main(){
    ll n, x; cin >> n >> x;
    cout << get_path_len(n-x, x) + x + n-x << endl;
    return 0;
}
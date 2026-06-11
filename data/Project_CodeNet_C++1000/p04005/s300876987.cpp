#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define endl "\n"
using namespace std;
using ll = long long;
using bnum = int64_t;
ll pi= static_cast<ll>(3.1415926535897932384626433l);
int diff(ll a){
    a = floor(a / 2);
    return a;
}
void solve(){
    vector<ll> s(3);
    for(int i = 0;i<3;++i){
        cin >> s[i];
    }sort(s.begin(),s.end());
    ll d = diff(s.at(2));
    cout << ((s.at(2) - d) * s.at(1) * s.at(0)) - (d * s.at(1) * s.at(0)) << endl;
}
int main(){
    solve();
}

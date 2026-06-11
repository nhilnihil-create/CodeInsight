#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;

template <class T1, class T2>
using dict = std::unordered_map<T1, T2>;

int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    cout << max(A*B,C*D) << endl;
}
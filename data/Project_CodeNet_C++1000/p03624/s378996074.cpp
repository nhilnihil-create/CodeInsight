#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    set<int> s;
    for(auto e:S){
        s.insert(e - 'a');
    }

    for(int i=0;i<=25;++i){
        if(s.count(i) != 1){
            cout << (char)(i+'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}

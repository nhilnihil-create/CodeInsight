#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    sort(all(S));
    for(int i=1;i<S.size();++i){
        if(S[i]==S[i-1]){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}

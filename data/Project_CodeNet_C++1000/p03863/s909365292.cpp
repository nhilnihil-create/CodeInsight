#include <bits/stdc++.h>

using ll = long long;
using namespace std;
constexpr ll inf = 1e15;
constexpr ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;

    cout<<((S.length() % 2 == 0) ^ (S[0] != S[S.length()-1]) ? "First" : "Second")<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N;
    cin >> N;
    unordered_map<int, bool> A;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A[a] = !A[a];
    }

    int ans = 0;
    for (auto itr = A.begin(); itr != A.end(); itr++)
    {
        if(itr->second){
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
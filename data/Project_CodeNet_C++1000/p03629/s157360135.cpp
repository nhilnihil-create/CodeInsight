#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int select(vector<int>& v){
    int ret = 0;
    for(int i=1; i<v.size(); i++){
        if(v[i] < v[ret]) ret = i;
    }
    return ret;
}

void fwd(string& A, Vvec<int>& dp){
    for(int i=A.size()-1; i>=0; i--){
        for(int k=0; k<26; k++) dp[i][k] = dp[i+1][k];
        int j = A[i] - 'a';
        int s = select(dp[i]);
        dp[i][j] = dp[i][s] + 1;
    }
}

string bwd(string& A, Vvec<int>& dp){
    string ans;
    int k = select(dp[0]);
    for(int i=0; i<A.size(); i++){
        if(A[i]-'a' != k) continue;
        ans += static_cast<char>('a'+k);
        k = select(dp[i+1]);
    }
    ans += static_cast<char>('a'+k);
    return ans;
}

int main()
{
    string A;
    cin >> A;
    Vvec<int> dp(A.size()+1, vector<int>(26, 1));

    fwd(A, dp);
    string ans = bwd(A, dp);

    cout << ans << endl;
}
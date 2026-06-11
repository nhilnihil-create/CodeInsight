#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans;
int N;
bool flag = false;

void solve(){
    if(N % 10 == 9) flag = true;

    N /= 10;

    if(N % 10 == 9) flag = true;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    cin >> N;

    solve();
}

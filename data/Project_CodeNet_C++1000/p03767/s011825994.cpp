#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    int n;
    cin >> n;
    vector<int> a(3*n);
    for(int i = 0; i < 3*n; i++)  cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n; i < 3*n-1; i+=2){
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}

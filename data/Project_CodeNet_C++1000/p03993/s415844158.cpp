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
    vector<int> a(n);
    vector<bool> right(n, false), left(n, false);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i == a[a[i]] && i < a[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}

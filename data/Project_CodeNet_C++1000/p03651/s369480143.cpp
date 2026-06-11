#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int gcd(int a,int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main() {
    int n,k;
    cin >> n >> k;
    int g = 0;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) g = gcd(a[i],g);
    bool ans = false;
    for (int i = 0;i < n;++i) if (a[i] >= k && (a[i]-k)%g == 0) ans = true;
    cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
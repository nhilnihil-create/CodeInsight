#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define cw(x) cout << (x) << endl
#define cww(x,y) cout << (x) << ' ' << y << endl
#define cwa(x) for(auto a:x) cout << a << ' ';cout << endl
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef unordered_set<int> usi;
typedef vector<pi> vpi;

int a[100000],n,i;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    for(cin >> n;n--;){
        cin >> i;
        a[i]++;
        a[i+1]++;
        a[i-1]++;
    }

    cout << *max_element(a,a+100000);

    return 0;
}

#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    bool a[26];
    memset(a,0,sizeof(a));
    string s;
    cin >> s;
    int n = s.length();
    for(int i=0;i<n;i++){
    	a[s[i] - 'a'] = true;
    }
    for(int i=0;i<26;i++){
    	if(!a[i]) {
    		cout << char(i + 'a') << endl;
    		return 0;
    	}
    }
    cout << "None" << endl;
    return 0;
}

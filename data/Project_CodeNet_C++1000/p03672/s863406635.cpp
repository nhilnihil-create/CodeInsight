#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    string s;
    cin>>s;
    for (int i=s.size()-1; i>=0; i--) {
        string res=s.substr(0,i);
        int n=res.size();
        if (n%2==0&&res.substr(0,n/2)==res.substr(n/2,n/2)) {
            cout<<n<<endl;
            return 0;
        }
    }
}

#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define for1(i, a, b) for (int i = (int)a; i < (int)(b); ++i)
#define rfor1(i, a, b) for (int i=(int)b-1;i>=(int)a;i--)
#define for2(i, a, b) for (int i = (int)a; i <= (int)(b); ++i)
#define for3(i, a, b) for (int i = (int)a; i < (int)(b); i=i+2)
#define for4(i, a, b) for (int i = (int)a; i <= (int)(b); i=i+2)
#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    if ((s1[s1.length()-1] == s2[0]) &&  (s2[s2.length()-1]==s3[0])){
        cout <<"YES" << "\n";
    }
    else {
        cout << "NO" << '\n';
    }


}








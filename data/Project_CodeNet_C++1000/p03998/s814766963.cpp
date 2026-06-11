
// 1827
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf 1e18
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 
 
int32_t main()
{
    fast;
    string sa, sb, sc, current; cin >> sa >> sb >> sc;
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    reverse(sc.begin(), sc.end());

    char c = 'a';
    char ans;

    while(true) {
        if(c == 'a') {
            if(sa.empty()) {
                ans = 'A';
                break;
            }
            c = sa[sa.size() - 1];
            sa.pop_back();
        }

        else if(c == 'b') {
            if(sb.empty()) {
                ans = 'B';
                break;
            }
            c = sb[sb.size() - 1];
            sb.pop_back();
        }

        else {
            if(sc.empty()) {
                ans = 'C';
                break;
            }
            c = sc[sc.size() - 1];
            sc.pop_back();
        }
    }

    cout << ans;

    return 0;
}
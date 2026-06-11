#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repm(i,m,n) for(int i=m; i<(n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool isdiff = true;
    rep(i, s.size())
    {
        int count = 0;
        rep(j, s.size())
        {
            //cout << s[i] << " , " << s[j] << endl;
            if(s[i] == s[j]) count++;

            //cout << count << endl;

            if(count == 2)
            {
                isdiff = false;
                break;
            }
        }
        //std::cout << std::endl;
        if(!isdiff) break;
    }

    if(isdiff) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
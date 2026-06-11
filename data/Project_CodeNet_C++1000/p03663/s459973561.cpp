/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

/* Nothing is impossible; impossible itself says "I'm possible" */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

#define int long long
#define N 500007

int test;

int n;

string res;

void solve()
{
    FOR(i,1,11){
        int l = (i==1 ? 1 : 0);
        int r = 10;

        while(l!=r){
            int mid = (l+r)/2;

            string pom = res;

            char c = '0'+mid;

            pom+=c;

            while(pom.size()<=10){
                pom+='9';
            }

            cout << "?" << " " << pom << endl;
            flusz;

            string tmp;

            cin >> tmp;

            if (tmp == "Y"){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        char c = l + '0';

        res += c;

        if (l == 9 && res.size()==1){
            cout << "?" << " " << "10" << endl;
            flusz;

            string tmp;

            cin >> tmp;

            if (tmp == "N"){
                break;
            }
        }

        if (l == 9 && res.size()!=1){
            string pom = res;
            pom.pop_back();

            pom += "00";

            cout << "?" << " " << pom << endl;
            flusz;

            string tmp;

            cin >> tmp;

            if (tmp == "N"){
                break;
            }
        }else if(l!=9){
            string pom = res;
            pom.pop_back();

            c = l + 1 + '0';

            pom += c;

            cout << "?" << " " << pom << endl;
            flusz;

            string tmp;

            cin >> tmp;

            if (tmp == "Y"){
                break;
            }
        }   
    }

    cout << "! " << res;

    return;
}

int32_t main()
{
    test=1;

    while(test--)
    {
        solve();
    }

  return 0;
}

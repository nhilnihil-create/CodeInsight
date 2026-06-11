#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
int n;
string s;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>s;
    s+=s[0];
    //cout<<s<<"\n";
    string anst;
    for(int i=0;i<4;i++){
        string ans;
        if(i==0)
        ans="WW";
        else if(i==1)
        ans="WS";
        else if(i==2)
        ans="SS";
        else 
        ans="SW";
        bool c=false;
        for(int j=1;j<=n;j++){
            //cout<<ans[ans.size()-1]<<" "<<ans[ans.size()-2]<<" "<<s[i]<<"\n";
            if(s[j]=='o'){
                if(ans[ans.size()-1]=='W'){
                    if(ans[ans.size()-2]=='W'){

                        ans+='S';
                    }
                    else{
                        ans+='W';
                    }
                }
                else{
                    if(ans[ans.size()-2]=='W'){
                        ans+='W';
                    }
                    else{
                        ans+='S';
                    }
                }
            }
            else{
                if(ans[ans.size()-1]=='W'){
                    if(ans[ans.size()-2]=='W'){
                        ans+='W';
                    }
                    else{
                        ans+='S';
                    }
                }
                else{
                    if(ans[ans.size()-2]=='W'){
                        ans+='S';
                    }
                    else{
                        ans+='W';
                    }
                }
            }
            //cout<<ans<<"\n";
        }
        if(ans[0]==ans[ans.size()-2]&&ans[1]==ans[ans.size()-1]) {
            //cout<<ans<<"\n";
            anst=ans;
            break;
        }
        if(i==3) return cout<<-1<<"\n",0; 
    }
    for(int i=0;i<anst.size()-2;i++){
        cout<<anst[i];
    }
    cout<<"\n";
}

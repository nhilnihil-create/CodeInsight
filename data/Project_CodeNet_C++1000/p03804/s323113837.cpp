/** author: __nishad__ **/
//#pragma GCC optimize(2)
//#pragma GCC optimize(3, "Ofast", "inline")
#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;
typedef vector<ll> vll ;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define precision(k) cout<<setprecision(k)<<fixed;
#define loop(i,a,b) for(ll i=(a);i<(b);++i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323
#define endl "\n"


char a[50][50], b[2500];
int n, m;


int solve(int i, int j)
{
    int count = 0, x=0;
    loop(o, i, i+m){
        loop(p, j, j+m){
            if(b[x] == a[o][p]){
                count++;
                x++;
            }

        }
    }
    return count;

}

int main()
{
    IOS;
    int count, x;

    cin>>n>>m;
    char s;

    loop(i, 0, n){
        loop(j, 0, n){
            cin>>a[i][j];
        }
    }

    loop(i, 0, m*m){
        cin>>b[i];
    }


    loop(i, 0, n){
        loop(j, 0, n){
            int res = 0;
            if(b[0] == a[i][j]){
                count = 0, x=0;
                loop(o, i, i+m){
                    loop(p, j, j+m){
                        if(b[x] == a[o][p]){
                            count++;
                            x++;
                        }

                    }
                }
            }
            if(count == m*m){
                cout<<"Yes";
                return 0;
            }
        }
    }

    cout<<"No";


}





























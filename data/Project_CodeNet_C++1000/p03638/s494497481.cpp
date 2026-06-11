#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()


using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll  = long long;

using point = complex<double>;


void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}


const double EPS = 1e-8;
const long long mod = 1e9+7;

const int dx[] = {0, 0,1,-1,1,-1, 1,-1};
const int dy[] = {1,-1,0, 0,1,-1,-1, 1};

const int N = 3e5 + 5;


int n , m;
int arr[200][200];
int x;
int col[10060];
bool vis[205][205];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> x;
    for(int i = 0; i < x; ++i)
        cin >> col[i];
    int lx , ly;
    lx = 0,ly = 0;
    bool isr = 1;
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < col[i]; ++j){
           arr[lx][ly] = i+1;
           if(isr)ly++;
           else ly--;
           if(ly == m){
                isr = 0;
                ly = m - 1;
                lx++;
           }else if(ly == -1){
                isr = 1;
                ly = 0;
                lx++;
           }

        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cout << arr[i][j] << " \n"[j == m - 1];
    return 0;
}

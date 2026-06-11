#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <functional>
#include <cstring>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = a; i < n; i++)
#define lrep(i,n) for(long long  i = 0; i < n; i++)
#define lrep2(i,a,n) for(long long i = a; i < n; i++)

typedef long long ll;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;

using namespace std;

int main() 
{
    int n;
    cin >> n;
    v_int a(n), b(n);

    irep(i, n) {
        cin >> a[i] >> b[i];
    }
    
    ll ans = 2;
    
    ll s = a[0];
    ll t = b[0];

    irep2(i, 1, n) {
        if(s * b[i] != t * a[i]) {
            ll j = max(s/a[i], t/b[i]);
            while(1) { 
                if(s <= a[i] * j && t <= b[i] * j) { 
                    s = a[i] * j;
                    t = b[i] * j;
                    break;
                } else {
                    j++;
                }
            }
        }
    }
    cout << s + t << endl; 
    return 0;
}

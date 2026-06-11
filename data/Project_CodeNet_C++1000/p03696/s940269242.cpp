#include <bits/stdc++.h>

#define PI 3.14159265359
#define EPS 1e-16
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(void)
{
    int n; 
    cin >> n;
    string s;
    cin >> s;
    
    int k = 0;
    int m = 0;
    irep(i, n) {
        if(s[i] == '(') {
            k++;
        } else {
            k--;
        }
        m = min(k, m);
    }
    cout << string(-m, '(') << s << string(k-m, ')') << endl;
    return 0;
}

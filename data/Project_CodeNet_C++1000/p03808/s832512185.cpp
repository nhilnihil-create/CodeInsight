#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n , a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    ll s = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        s += a[i];
    }
    ll tmp = 0;
    if(s % ((ll)n * (n + 1) / 2))return cout << "NO" , 0;
    s /= (ll)n * (n + 1) / 2;
    for(int i = 0 ; i < n ; ++i){
        if(s + a[i] - a[(i + 1) % n] < 0)return cout << "NO" , 0;
        tmp += (s + a[i] - a[(i + 1) % n]) / n;
    }
    puts(tmp == s ? "YES" : "NO");
}

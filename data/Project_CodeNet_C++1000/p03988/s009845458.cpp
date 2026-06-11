#include<bits/stdc++.h>

using namespace std;
#define taskname "A"
#define pb  push_back
#define mp  make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, a[maxn];
map<int,int> mmap;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP", "r",stdin);
        freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        mmap[a[i]]++;
    }
    bool ok = 1;
    int d = *max_element(a + 1 , a + n + 1);
    for(int i = 0 ; i <= d ; ++i){
        mmap[max(i , d - i)]--;
    }
    for(auto & c : mmap){
        if(c.second < 0)ok = 0;
        if(c.second > 0 && c.first < (d / 2 +d % 2) + 1){
            ok = 0;
        }
    }
    if(ok)cout << "Possible";
    else cout << "Impossible";
}

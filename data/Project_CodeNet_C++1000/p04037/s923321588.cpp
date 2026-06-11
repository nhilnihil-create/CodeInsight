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
const int maxn = 1e5 + 5;

int n, a[maxn] , x;

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
    }
    sort(a + 1 , a + n + 1,greater<int>());
    int now = 0;
    for(int i = 1 ; i <= n + 1 ; ++i){
        if(i > a[i]){
            now = i - 1;
            break;
        }
    }
//    cout << now << endl;
//    cout << (upper_bound(a + 1 , a + n + 1 , now, greater<int>()) - a - now - 1);
    if((a[now] - now) % 2 || (upper_bound(a + 1 , a + n + 1 , now, greater<int>()) - a - now - 1) % 2)cout << "First";
    else cout << "Second";
}

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <time.h>

#define mst(a,b)memset(a, b, sizeof(a))
#define repi(a,b)for(int i = a; i < b; i++)
#define repj(a,b)for(int j = a; j < b; j++)
#define pii pair<int,int>
#define print_time()cout<<clock()/CLOCKS_PER_SEC<<" s"<<endl;

#ifdef LOCAL
#define fre()freopen("in.txt","r",stdin)
#endif
#ifndef LOCAL
#define fre()
#endif

//static int x = []() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(NULL);
//	return 0;
//}();

#define FASTIO
#ifdef FASTIO
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
//#define scanf abcabc
//#define printf abcabc
#endif
//#ifndef FASTIO
//#define cin abcabc
//#define cout abcabc
//#endif

typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

using namespace std;


int main(){
    ll n,m;cin>>n>>m;
    if(n>m)swap(n,m);
    if(m-n<2)cout<<"Brown\n";
    else cout<<"Alice\n";
    return 0;
}

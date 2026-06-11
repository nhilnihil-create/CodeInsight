#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue> //priority_queue
#include <map>
#include <set> //multiset set<int,greater<int>>大到小
#include <vector>// ::iterator it;
#include <stack>
#include <cmath> // auto &Name : STLName  Name.
#include <utility>
#include <sstream>
#include <string>//__builtin_popcount(ans);//获取某个数二进制位1的个数
#define mod 1000000007
#define mod9 998244353
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ld;
const db eps=1e-10;
const int INF = 0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int N=1e5+7;
using namespace std;

int t,n,m,k,ans=0,cnt=0,sum=0;
int main(){
    scanf("%d%d",&n,&m);
    printf("%d\n",n*n-m);
    return 0;
}
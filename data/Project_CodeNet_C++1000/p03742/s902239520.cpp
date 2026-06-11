#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const int INF=1000000000;




int main(){
    LL x,y;cin >> x >> y;
    if(abs(x-y)<=1) puts("Brown");
    else puts("Alice");
    return 0;
}


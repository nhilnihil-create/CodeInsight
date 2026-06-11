#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define PI acos(-1.0)
const int N=1e5 + 5;
const int M=1e7 + 5;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i;
    ll s[N],d[N];
    cin>>n;
    ll tot = 0;
    for(i=0;i<n;i++){
        cin>>s[i];
        tot += s[i];
        if(i>0) d[i]=s[i]-s[i-1];
    } 
    d[0]=s[0]-s[n-1];
    ll t;
    ll lu = ((ll)n*(n+1))/2;
    if(tot%lu != 0){
        cout << "NO\n";
        return 0;
    }
    t = tot/lu;
    for(i=0;i<n;i++){
        d[i]=d[i]-t;
        //cout << d[i] << endl;
    }

    bool ok = true;
    ll cnt = 0;
    ll foo = n;
    for(i=0;i<n;i++){
        if(d[i]>0){
            ok=false;
            break;
        }
        d[i]*=-1;
        if(d[i]%foo!=0){
            ok=false;
            break;
        }
        cnt += d[i]/foo;
    }
    if(!ok || cnt!=t){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";



 
    return 0;
}
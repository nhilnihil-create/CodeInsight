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
const int M=1e5 + 5;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,s[N],a[N];
    for(i=0;i<N;i++){
        a[i]=0;
    }
    int d=-1; 
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s[i];
        d=max(d,s[i]);
        a[s[i]]++;
    }
    bool ok = true;
    if(d%2==1){
        int cnt = 0;
        for(i=d;i>=d/2+1;i--){
            if(i == d/2+1){
                if(a[i]!=2) ok = false;
            }
            else{
                if(a[i]<2) ok = false;
            }
            cnt += a[i];
        }
        if(cnt != n) ok = false;
    }
    else{
        int cnt = 0;
        for(i=d;i>=d/2;i--){
            if(i!=d/2){
                if(a[i]<2) ok = false;
            }
            else{
                if(a[i]!=1) ok = false;
            }
            cnt += a[i];
        }
        if(cnt != n) ok = false;
    }

    cout << (ok ? "Possible\n" : "Impossible\n");
 
    return 0;
}
#include <iostream>
#include <bits/stdtr1c++.h>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
typedef long long ll;
const int N = 100005;
const int MOD = 1000000007;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    int sum=0;
    for(int i=1;i<=n;i++) {cin >> a[i];sum+=a[i];}
    int m;cin >> m;
    while(m--){
        int i,x;
        cin >> i >> x;
        int prev=sum;
        cout  << sum-a[i]+x << endl;;
    }

    
    return 0;
}

#pragma region header
#define _GLIBCXX_DEBUG 
#include <iostream>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
#define int long long
signed main() {
    int N,K;
    cin>>N>>K;
    int ans=0;

    vector<int>l(N);
    for(int i=0;i<N;i++){
        cin>>l[i];
    }
    sort(l.begin(), l.end()); // {1, 2, 2, 5}
    reverse(l.begin(), l.end());
    for(int i=0;i<K;i++){
        ans+=l[i];
    }
    cout<<ans<<endl;
}
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
    int INF=1000000007;
    int N;
    cin>>N;
    int ans=1;

    for(int i=1;i<=N;i++){
        ans=ans*i;
        if(ans>=INF){
            ans=ans%INF;
        }
    }
    cout<<ans<<endl;
}
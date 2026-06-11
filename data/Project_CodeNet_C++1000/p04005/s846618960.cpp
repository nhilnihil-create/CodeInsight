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
    int A,B,C;
    cin>>A>>B>>C;

    if(A%2==0||B%2==0||C%2==0){
        cout<<0<<endl;
    }
    else{
        cout<<min(A,min(B,C))*((A+B+C)-(min(A,min(B,C))+max(A,max(B,C))))<<endl;
    }
}

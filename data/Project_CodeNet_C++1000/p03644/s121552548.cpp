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
#define int long long
using namespace std;
signed main() {
	int N;
    cin>>N;

    if(N<2){
        cout<<1<<endl;
    }
    else if(N<4){
        cout<<2<<endl;
    }
    else if(N<8){
        cout<<4<<endl;
    }
    else if(N<16){
        cout<<8<<endl;
    }
    else if(N<32){
        cout<<16<<endl;
    }
    else if(N<64){
        cout<<32<<endl;
    }
    else{
        cout<<64<<endl;
    }
}
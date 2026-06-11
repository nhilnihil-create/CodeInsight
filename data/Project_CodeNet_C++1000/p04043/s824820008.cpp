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

int main() {
    int A,B,C;
    cin>>A>>B>>C;
    int a=0;
    int b=0;

    if(A==5){
        a++;
    }
    else{
        b++;
    }
    if(B==5){
        a++;
    }
    else{
        b++;
    }
    if(C==5){
        a++;
    }
    else{
        b++;
    }
    if(a==2&&b==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
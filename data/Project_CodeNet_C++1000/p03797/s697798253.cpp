#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <fstream>
#include <complex>
#define _USE_CMATH_DEFINES

const long INF = (1l << 30);
const long LINF = (1l << 60); //1.15*10^18

long n, m;

int main(){
    scanf("%ld%ld", &n, &m);
    if(n * 2 > m){
        printf("%ld\n", m / 2l);
    }else{
        printf("%ld\n", n + (m-2l*n)/4l);
    }
}

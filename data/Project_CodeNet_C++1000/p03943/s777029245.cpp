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

long a[3];

int main(){
    for(int i = 0; i < 3; i++){
        scanf("%ld", a+i);
    }
    for(int i = 0 ;i < 3; i++){
        if(a[i] == a[(i+1)%3] + a[(i+2)%3]){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

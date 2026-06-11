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

const long INF = (1l << 30);
const long LINF = (1l << 60);

long n;
long a[100005];
long max = 0;
long min = LINF;

int main(){
    scanf("%ld", &n);
    for(int i = 0; i < n; i++){
        scanf("%ld", &a[i]);
        max = std::max(max, a[i]);
        min = std::min(min, a[i]);
    }
    if(max - min >= 2){
        printf("No\n");
        return 0;
    }else if(max - min == 1){
        long cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == max){
                cnt++;
            }
        }
        if(n-max+1 <= cnt && cnt <= 2*(n-max)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }else{
        if(2*max <= n || max == n-1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}

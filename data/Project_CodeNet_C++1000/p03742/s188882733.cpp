#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <time.h>
using namespace std;
int main(){
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    long long int ans=abs(x-y);
    if(ans>1){
        printf("Alice\n");
    }
    else {
        printf("Brown\n");
    }
    return 0;
}

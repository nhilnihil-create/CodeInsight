#include <iostream>
#include<iomanip>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

const int NN=1e5+10;

int n;
int a[NN];
int b[NN];
int ans[NN];



int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    if(abs(x-y)>=2){
        printf("Alice\n");
    }
    else{
        printf("Brown\n");
    }
}




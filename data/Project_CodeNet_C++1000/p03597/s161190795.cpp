#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,a,sum;
    scanf("%d",&n);
    scanf("%d",&a);
    sum=pow(n,2);
    printf("%d\n",sum-a);
    return 0;
}
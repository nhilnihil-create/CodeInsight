#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int x, a, b;

int main()
{
    scanf("%d %d %d", &x, &a, &b);
    if (abs(x-a) < abs(x-b)) printf("A\n");
    else printf("B\n");
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
int main()
{
    int x, total = 0;
    scanf("%d", &x);
    for(; x > 0; x -= ++total){}
    printf("%d\n", total);
}
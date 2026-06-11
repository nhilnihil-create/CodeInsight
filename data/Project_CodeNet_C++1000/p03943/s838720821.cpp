#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

   if(c == a + b || b == a + c || a == b + c)
    printf("Yes\n");
   else
    printf("No\n");
    return 0;
}

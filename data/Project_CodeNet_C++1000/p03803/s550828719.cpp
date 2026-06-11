#include <cstdio>
using namespace std;
int main ()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==b)
        printf("Draw\n");

    else if(a<b)
    {
        if(a==1)
        {
            printf("Alice\n");
        }
        else
            printf("Bob\n");
    }
    else if(a>b)
    {
        if(b==1)
            printf("Bob\n");
        else
            printf("Alice\n");
    }

    return 0;
}
#include<bits/stdc++.h>
#define endl "\n"
#define PI acos(-1)
#define BMW_GTR ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
using namespace std;

//ll const n = 50005;

int main()
{
   // BMW_GTR;

    char A[102], B[102], a[102], b[102];

    scanf("%s %s", &A, &B);

    for(int i = 0; i < 101; i++)
    {
        a[i] = '0';
        b[i] = '0';
    }

    int j = 100;
    for(int i = strlen(A) - 1; i >= 0; i--)
    {
        a[j] = A[i];
        j--;
    }

    j = 100;
    for(int i = strlen(B) - 1; i >= 0; i--)
    {
        b[j] = B[i];
        j--;
    }

    for(int i = 101 - max(strlen(A), strlen(B)); i < 101; i++)
    {
        if(a[i] > b[i])
        {
            printf("GREATER");
            break;
        }

        if(a[i] < b[i])
        {
            printf("LESS");
            break;
        }

        else
        {
            printf("EQUAL");
            break;
        }
    }

    return 0;
}

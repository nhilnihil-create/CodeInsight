#include <stdio.h>
#include <string.h>

int main()
{
    char A[11];
    char B[11];
    char C[11];

    scanf("%s %s %s", A, B, C);

    int lastA = strlen(A) - 1, lastB = strlen(B) - 1;

    if (A[lastA] == B[0] && B[lastB] == C[0])
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
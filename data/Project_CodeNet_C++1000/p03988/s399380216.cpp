#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int occurences[105];
int diameter;
bool isPossible = true;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int a; scanf("%d", &a);
        occurences[a]++;
        diameter = max(diameter, a);
    }
    for (int i = (diameter + 1) / 2; i <= diameter && isPossible; i++)
    {
        if (i == (diameter + 1) / 2)
        {
            if ((diameter % 2 == 0 && occurences[i] != 1) || (diameter % 2 == 1 && occurences[i] != 2)) isPossible = false;
        }
        else if (occurences[i] < 2) isPossible = false;
    }
    for (int i = 0; i < (diameter + 1) / 2 && isPossible; i++)
    {
        if (occurences[i] != 0) isPossible = false;
    }
    if (isPossible) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
int N;
int A[100010];
vector<pii> V;

int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",A + i);
    if(N == 1)
    {
        if(A[0] % 2)printf("Second\n");
        else printf("First\n");
        return 0;
    }

    sort(A,A + N);
    reverse(A,A + N);
    for(int i = 0; i < N; i++)
    {
        if(i == N - 1 || (A[i] != A[i + 1]))
        V.push_back(make_pair(i + 1,A[i]));
    }

    if(V.size() == 1)
    {
        if((abs(V[0].second - N)) % 2 == 0)printf("Second\n");
        else printf("First\n");
        return 0;
    }

    int l = 0;
    while(l != V.size() - 1 && V[l].first <= V[l].second)l++;

    int res = 0;
    int a = V[l - 1].first,b = V[l].second;
    if(a == b)
    {
        if((V[l - 1].second - a) % 2)res = 1;
        if((V[l].first - a) % 2)res = 1;
        if(res == 1)printf("First\n");
        else printf("Second\n");
    }
    if(a > b)// l - 1とくっつく
    {
        if((V[l - 1].second - V[l - 1].first) % 2)printf("First\n");
        else printf("Second\n");
    }
    if(a < b)
    {
        if((V[l].first - V[l].second) % 2)printf("First\n");
        else printf("Second\n");
    }
    return 0;
}

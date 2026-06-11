#include <iostream>
using namespace std;
int N, Min = 1000000005;
int A[100005];
int cnt[2];
long long sum = 0;
void Read()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        sum += A[i] - 1;
        Min = min(Min, A[i]);
        cnt[A[i] % 2]++;
    }
}

int GCD(int a, int b)
{
    int r = a % b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
void Print(int player)
{
    if(player == 0)
        cout << "First\n";
    else
        cout << "Second\n";
}
void Solve(int player)
{
    if(Min == 1)
    {
        if(sum % 2 == 1)
        {
            Print(player);
        }
        else
            Print(1 - player);
        return;
    }
    if(sum % 2 == 1)
    {
        Print(player);
        return;
    }
    if(cnt[1] > 1)
    {
        Print(1 - player);
        return;
    }
    cnt[0] = cnt[1] = 0;
    sum = 0;
    Min = 1000000005;
    int g = A[1];
    if(A[1] % 2 == 1)
        --A[1], g = A[1];
    for(int i = 2; i <= N; i++)
    {
        if(A[i] % 2 == 1)
            --A[i];
        g = GCD(g, A[i]);
    }
    for(int i = 1; i <= N; i++)
    {
        A[i] /= g;
        sum += A[i] - 1;
        Min = min(Min, A[i]);
        cnt[A[i] % 2]++;
    }
    Solve(1 - player);
}
int main()
{
    Read();
    Solve(0);
    return 0;
}

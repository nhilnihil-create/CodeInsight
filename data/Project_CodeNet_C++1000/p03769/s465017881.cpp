#include <iostream>
#include <cmath>
using namespace std;
long long N;
int S[205], cnt, curr = 1;
int B[205], A[205];
void Fill(int log)
{
    if(cnt > 0)
    {
        int pos = log + 1;
        B[pos]++;
        B[++cnt]--;
        A[cnt] = log + 1;
    }
    else
    {
        for(int i = 1; i <= log; i++)
            A[i] = i;
        cnt = log;
    }
    /*S[++cnt] = curr;
    S[++cnt] = curr;
    ++curr;*/
}
int findLog(long long x)
{
    int log = 0;
    while((1LL << log) <= x)
        ++log;
    log--;
    return log;
}
void Solve()
{
    while(N > 0)
    {
        long long log = findLog(N);
        Fill(log);
        N -= (1LL << log);
    }
}
int main()
{
    cin >> N;
    N++;
    Solve();
    for(int i = 1; i <= cnt; i++)
    {
        B[i] = B[i - 1] + B[i];
        A[i] += B[i];
    }
    cout << cnt * 2 << "\n";
    for(int i = 1; i <= cnt; i++)
        cout << A[i] << " " ;
    for(int i = 1; i <= cnt; i++)
        cout << i << " ";
    cout << "\n";
    return 0;
}

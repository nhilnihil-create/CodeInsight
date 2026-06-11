// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N;
    int tm = 0, tp = 0;
    vector < int > vec;
    scanf("%lld", &N); N ++;
    while (N > 1)
    {
        if (N & 1)
            vec.push_back(-- tm);
        vec.push_back(tp ++);
        N >>= 1;
    }
    int K = (int)vec.size();
    printf("%d\n", K * 2);
    for (int i = 1; i <= K; i ++)
        printf("%d ", i);
    for (int i : vec)
        printf("%d ", (i + K) % K + 1);
    return 0;
}
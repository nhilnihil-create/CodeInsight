#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int load[N] = {0};

    for(int i=0; i<M; i++)
    {
        int a,b;
        cin >> a >> b;
        load[a-1] += 1;
        load[b-1] += 1;
    }

    for(int i=0; i<N; i++) cout << load[i] << endl;
    return 0;
}
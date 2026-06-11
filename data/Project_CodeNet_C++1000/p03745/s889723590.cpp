#include <bits/stdc++.h>
using namespace std;
 
int main(void) 
{
    int N;
    cin >> N;

    vector<int> A(N);

    for(int i=0;i<N;++i)
    {
        cin >> A[i];
    }

    int ans = 1;

    int gl = 0;
    for(int i=1;i<N;++i)
    {
        int d = 0, k = 0;

        if (A[i-1]<A[i]) d=1;
        else if (A[i-1]>A[i]) d=-1;
        else d = 0;
        if (gl!=0&&d!=0&&gl!=d) 
        {
            ans++;
            gl = 0;
        }
        else
        {
            if (d!=0) gl=d;
        }
    }

    cout << ans << endl;

    return 0;
}

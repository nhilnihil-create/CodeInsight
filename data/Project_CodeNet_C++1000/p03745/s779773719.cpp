#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll result = 0;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++)
    {
        while (i + 1 < N && A[i + 1] == A[i])
        {
            i++;
        }
        if (i + 1 < N && A[i + 1] > A[i])
        {
            while (i + 1 < N && A[i + 1] >= A[i])i++;
        }
        else if (i + 1 < N && A[i + 1] < A[i])
        {
            while (i + 1 < N && A[i + 1] <= A[i])
                i++;
        }
        result++;
    }
    cout << result << endl;
}
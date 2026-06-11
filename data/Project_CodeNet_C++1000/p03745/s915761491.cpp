#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    int cut = 1;
    int grad = 0;
    for(int i = 1; i < N; i++){
        if(A[i] == A[i-1]) continue;
        int neg = (A[i] > A[i-1]) ? 1 : -1;
        if(grad == 0) grad = neg;
        if(neg == grad) continue;
        else {
            cut++;
            grad = 0;
        }
    }

    cout << cut << endl;

    return 0;
}

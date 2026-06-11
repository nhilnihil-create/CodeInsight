#include<iostream>
#include<queue>
using namespace std;

const int MAX = 1e5+1;
int A[MAX];

int main(){
    int n, l; cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    int mx = 0;
    int tie = 0;
    for (int i = 1; i < n; i++)
    {
        if (mx < A[i]+A[i+1])
        {
            mx = A[i]+A[i+1];
            tie = i;
        }
    }
    if (mx < l)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 1; i < tie; i++)
    {
        cout << i << endl;
    }
    for (int i = n-1; i > tie; i--)
    {
        cout << i << endl;
    }
    cout << tie << endl;
}
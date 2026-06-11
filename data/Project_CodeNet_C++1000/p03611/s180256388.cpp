#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    map<int, int> p;

    for (int i = 0; i < N; i++)
    {
        p[A[i] - 1] += 1;
        p[A[i] + 1] += 1;
        p[A[i]] += 1;
    }
    
    int max = 0;
    for(auto i : p) {
        if (max < i.second)
        {
            max = i.second;
        }
        
    }

    cout << max << endl;
    return 0;

}
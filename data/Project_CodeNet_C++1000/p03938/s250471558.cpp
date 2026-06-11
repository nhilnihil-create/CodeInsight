#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> permutation(n);

    for (long long &element : permutation)
    {
        cin >> element;
        element--;
    }

    vector<long long> firstSequence(n);
    vector<long long> secondSequence(n);

    firstSequence[0] = 1;
    for (long long i = 0; i < n - 1; i++)
        firstSequence[i + 1] = firstSequence[i] + n;

    for (int i = 0; i < n; i++)
        secondSequence[permutation[i]] = (firstSequence[n - 1] - firstSequence[permutation[i]]) + i + 1;

    for (long long x : firstSequence)
        cout << x << " ";
    cout << endl;

    for (long long x : secondSequence)
        cout << x << " ";
    cout << endl;

    return 0;
}
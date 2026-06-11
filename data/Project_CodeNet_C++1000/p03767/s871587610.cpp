#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> participant(3 * n);

    for (long long &strength : participant)
        cin >> strength;

    sort(participant.begin(), participant.end(), greater<int>());

    long long answer = 0;
    for (int i = 0; i < n; i++)
        answer += participant[2 * i + 1];

    cout << answer << endl;
    
    return 0;
}
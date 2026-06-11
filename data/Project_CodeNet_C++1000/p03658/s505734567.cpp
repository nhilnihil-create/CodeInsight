#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> l;
    int ans = 0;

    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        l.push_back(temp);
    }
    sort(l.begin(), l.end(), greater<int>());

    for(int i=0; i<K; i++) ans += l[i];
    cout << ans << endl;
    return 0;
}
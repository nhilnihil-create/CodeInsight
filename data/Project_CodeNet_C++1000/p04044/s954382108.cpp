#include <bits/stdc++.h>

using namespace std;

int N, L;

int main()
{
    cin >> N >> L;
    string arr[N];
    for (int i = 0 ; i < N ; i ++) {
        cin >> arr[i];
    }
    sort (arr, arr + N);
    for (int i = 0 ; i < N ; i ++) {
        cout << arr[i];
    }
    return 0;
}
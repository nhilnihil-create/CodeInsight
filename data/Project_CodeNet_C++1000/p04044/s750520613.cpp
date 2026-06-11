#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;

int main() {
    scanf("%d%d", &N, &L);
    vector<string> strs(N);
    for (int i = 0; i < N; i++)
        cin >> strs[i];
    sort(strs.begin(), strs.end());

    string ans;
    for (int i = 0; i < N; i++)
        ans += strs[i];

    cout << ans << endl;
    return 0;
}
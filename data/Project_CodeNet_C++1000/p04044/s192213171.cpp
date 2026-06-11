#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, L;
    cin >> N >> L;

    vector<string> v(N);
    for(int i = 0; i < N; i ++)
        cin >> v[i];

    sort(v.begin(), v.end());

    string res = "";
    for(const string& s: v) res += s;
    cout << res << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, L;

    cin >> N >> L;

    vector<string> S(N, "");

    for(int i = 0; i < N; ++i)
    {
        cin >> S[i];
    }

    auto f = [L](const string& a, const string& b){
        for(int i = 0; i < L; ++i)
        {
            if(a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
        return true;
    };

    std::sort(S.begin(), S.end());

    for(int i = 0; i < N; ++i)
    {
        cout << S[i];
    }
    cout << endl;

    return 0;
}


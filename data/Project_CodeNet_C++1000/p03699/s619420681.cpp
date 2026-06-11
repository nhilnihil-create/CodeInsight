#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> s(N);
    vector<vector<int>> dig1s(10, vector<int>(0));
    vector<int> nondeci;

    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> s[i];
        sum += s[i];
        dig1s[s[i]%10].push_back(s[i]);
        if(s[i] % 10 != 0) nondeci.push_back(s[i]);
    }

    if(sum % 10 == 0 && nondeci.size() > 0){
        int min = *min_element(nondeci.begin(), nondeci.end());
        sum -= min;
    }

    cout << ((sum % 10 == 0) ? 0 : sum) << endl;

    return 0;
}

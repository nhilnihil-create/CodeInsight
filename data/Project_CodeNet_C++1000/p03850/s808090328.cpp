#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int N;

int main()
{
    cin >> N;
    char c;
    lint sum, now, msum = 0;
    cin >> sum;
    lint tmp = 0;
    vector<lint> mlst;
    for (int i=1; i<N; i++)
    {
        cin >> c >> now;
        sum += now;
        if (c == '-') {
            mlst.push_back(tmp);
            msum += now;
            tmp = msum;
        }
        else {
            tmp += now;
        }
    }
    if (!mlst.empty()) mlst[0] = -1;
    mlst.push_back(msum);
    sort(mlst.begin(), mlst.end());
    cout << sum - mlst[1] * 2 << endl;
}

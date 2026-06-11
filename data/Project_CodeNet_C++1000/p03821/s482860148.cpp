#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int64_t, int>> numb(n);
    for (auto & x: numb) {
        cin >> x.first >> x.second;
    }
    int64_t sum = 0;
    for (int i = n - 1; i > -1; --i) {
        numb[i].first += sum;
        if (numb[i].first % numb[i].second) {
            int64_t upd = (numb[i].first / numb[i].second + 1) * numb[i].second - numb[i].first;
            sum += upd;
        }
    }
    cout << sum;



    return 0;
}

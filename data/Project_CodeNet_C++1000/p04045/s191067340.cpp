#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> d;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        d.push_back(a);
    }

    int ans = 0;

    while(true) {
        int n_check = n;
        int kodawari_found = 0;
        while(n_check > 0) {
            int digit = n_check % 10;

            auto itr = std::find(d.begin(), d.end(), digit);
            if( itr != d.end() ) {
                kodawari_found = 1;
                break;
            }

            n_check /= 10;
        }

        if (kodawari_found == 0) {
            ans = n;
            break;
        }

        n++;
    }

    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int64_t objects, max_weight;
    cin >> objects >> max_weight;

    map<int64_t, int64_t> max_values;
    max_values[0] = 0;

    for (int64_t i = 0; i < objects; i += 1) {
        int64_t weight, value;
        cin >> weight >> value;

        map<int64_t, int64_t> new_values(max_values);
        for (const auto &p : max_values) {
            auto new_weight = p.first + weight;
            auto new_value = p.second + value;

            if (new_weight <= max_weight) {
                new_values[new_weight] = max(new_values[new_weight], new_value);
            }
        }
        max_values = new_values;
    }

    int64_t res = 0;
    for (const auto &p : max_values) {
        res = max(res, p.second);
    }

    cout << res << "\n";
    return 0;
}

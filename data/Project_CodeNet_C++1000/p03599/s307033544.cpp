#include <iostream>
#include <limits>

using namespace std;

int main() {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    long long water = 0;
    long long sugar = 0;
    double max_concentration = .0;

    size_t op = 0;
    while (true) {
        long long tmp_water = 100 * a * op;
        if (tmp_water > f) {
            break;
        }

        for (int i = 0; tmp_water + i * c <= f; ++i) {
            long long residual = tmp_water / 100 * e - i * c;
            if (residual < 0) {
                break;
            }
            long long tmp_sugar = i * c;
            long long sugar_op = residual / d;
            while (sugar_op >= 0 && tmp_water + tmp_sugar + sugar_op * d > f) {
                --sugar_op;
            }
            tmp_sugar += (sugar_op > 0) ? sugar_op * d : 0;
            double concentration = (tmp_sugar == 0) ? 0. : 100. * static_cast<double>(tmp_sugar) / static_cast<double>(tmp_water + tmp_sugar);
            if (concentration >= max_concentration) {
                max_concentration = concentration;
                water = tmp_water;
                sugar = tmp_sugar;
            }

            if (residual == 0) break;
        }

        while (tmp_water + 100 * b <= f) {
            tmp_water += 100 * b;
            for (int i = 0; tmp_water + i * c <= f; ++i) {
                long long residual = tmp_water / 100 * e - i * c;
                if (residual < 0) {
                    break;
                }
                long long tmp_sugar = i * c;
                long long sugar_op = residual / d;
                while (sugar_op >= 0 && tmp_water + tmp_sugar + sugar_op * d > f) {
                    --sugar_op;
                }
                tmp_sugar += (sugar_op > 0) ? sugar_op * d : 0;
                double concentration = (tmp_sugar == 0) ? 0. : 100. * static_cast<double>(tmp_sugar) / static_cast<double>(tmp_water + tmp_sugar);
                if (concentration >= max_concentration) {
                    max_concentration = concentration;
                    water = tmp_water;
                    sugar = tmp_sugar;
                }

                if (residual == 0) break;
            }
        }
        ++op;
    }

    cout << water + sugar << " " << sugar << endl;
    return EXIT_SUCCESS;
}
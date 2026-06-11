#include <iostream>
#include <vector>
static std::vector<std::vector<bool>> memo(3000, std::vector<bool>(3000, false));
static int MW = 0, MS =0;

static void rec(
    const int w,
    const int s,
    const int a,
    const int b,
    const int c,
    const int d,
    const int e,
    const int f)
{
    if (w > f || s > f || w + s > f) {
        return;
    }
    if (memo[w][s]) {
        return;
    }
    memo[w][s] = true;

    if (s <= (e * w / 100)) {
        if (MW + MS == 0) {
            MW = w;
            MS = s;
        }
        else if (s*(MW+MS) >= MS*(w+s)) {
            MW = w;
            MS = s;
        }
    }

    rec(w + 100 * a, s, a, b, c, d, e, f);
    rec(w + 100 * b, s, a, b, c, d, e, f);
    rec(w, s + c, a, b, c, d, e, f);
    rec(w, s + d, a, b, c, d, e, f);
}

int main() {
    int a, b, c, d, e, f; std::cin >> a >> b >> c >> d >> e >> f;

    rec(0, 0, a, b, c, d, e, f);
    std::cout << MW + MS << " " << MS << std::endl;
    return 0;
}
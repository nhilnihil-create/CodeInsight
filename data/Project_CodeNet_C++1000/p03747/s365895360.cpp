#include <stdint.h>
#include <stdio.h>
#include <vector>

unsigned readUnsigned() {
    int c;
    do { c = ::getchar_unlocked(); } while (c < '0');
    unsigned result = c - '0';
    while ((c = ::getchar_unlocked()) >= '0') {
        result *= 10;
        result += c - '0';
    }
    return result;
}

void writeUnsignedLn(unsigned x) {
    static const unsigned MAX_DIGITS = 10;
    static const unsigned BUF_SIZE = MAX_DIGITS + 1;
    static char buffer[BUF_SIZE] = {0};
    buffer[BUF_SIZE - 1] = '\n';
    unsigned i = BUF_SIZE - 1;
    do {
        buffer[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    ::fwrite_unlocked(buffer + i, 1, BUF_SIZE - i, stdout);
}

uint64_t N, L, T;
std::vector<uint64_t> xs, W;

std::vector<unsigned> solve() {
    std::vector<uint64_t> crossings(N);

    struct xid { uint64_t x, id; };
    std::vector<xid> left, right;
    for (unsigned n = 0; n <= 1; ++n) {
        for (unsigned i = 0; i < N; ++i) {
            if (W[i] == 1) {
                right.push_back({xs[i] + n*L, i});
            }
            else {
                left.push_back({xs[i] + n*L, i});
            }
        }
    }

    uint64_t numleft = left.size() / 2;
    uint64_t numright = right.size() / 2;

    for (unsigned i = 0, min = 0, max = 0; i < N; ++i) {
        if (W[i] != 1) {
            continue;
        }
        crossings[i] = (2 * T) / L * numleft;
        uint64_t lo = xs[i];
        uint64_t hi = xs[i] + 2 * T % L;
        for (; min < left.size() && left[min].x < lo; ++min);
        for (; max < left.size() && left[max].x < hi; ++max);
        crossings[i] += max - min;
    }

    for (unsigned i = 0, min = 0, max = 0; i < N; ++i) {
        if (W[i] != 2) {
            continue;
        }
        crossings[i] = (2 * T) / L * numright;
        uint64_t lo = xs[i] + L - 2 * T % L;
        uint64_t hi = xs[i] + L;
        for (; min < right.size() && right[min].x <= lo; ++min);
        for (; max < right.size() && right[max].x <= hi; ++max);
        crossings[i] += max - min;
    }

    std::vector<unsigned> result(N);
    for (unsigned i = 0; i < N; ++i) {
        if (W[i] == 1) {
            unsigned j = (i + crossings[i]) % N;
            unsigned t = (xs[i] + T) % L;
            result[j] = t;
        }
        else {
            unsigned j = (i - crossings[i] % N + N) % N;
            unsigned t = (xs[i] - T%L + L) % L;
            result[j] = t;
        }
    }
    return result;
}

int main() {
    N = readUnsigned();
    L = readUnsigned() * 2;
    T = readUnsigned() * 2;

    xs.resize(N);
    W.resize(N);
    for (unsigned i = 0; i < N; ++i) {
        xs[i] = readUnsigned() * 2;
        W[i] = readUnsigned();
    }

    std::vector<unsigned> result = solve();
    for (unsigned i = 0; i < N; ++i) {
        writeUnsignedLn(result[i] / 2);
    }
}

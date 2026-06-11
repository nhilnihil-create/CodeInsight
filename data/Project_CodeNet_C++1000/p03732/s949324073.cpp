#include <iostream>
#include <map>

int main() {
    unsigned int N, W; std::cin >> N >> W;
    std::map<unsigned int /* w */, unsigned int /* v */> m;
    m.insert(std::make_pair(0, 0));
    for (unsigned int i = 0; i < N; i++) {
        unsigned int w, v; std::cin >> w >> v;
        decltype(m) mm(m);
        for (const auto& l: mm) {
            auto nw = l.first + w;
            if (nw > W) {
                continue;
            }
            auto nv = l.second + v;
            const auto f = m.find(nw);
            if (f == m.end() || nv > f->second) {
                m[nw] = nv;
            }
        }
    }

    unsigned int mm = 0;
    for (const auto& l: m) {
        mm = std::max(mm, l.second);
    }

    std::cout << mm << std::endl;
    return 0;
}
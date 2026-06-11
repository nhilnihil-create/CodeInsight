#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

template<typename T>
class CoordinateCompression{
    std::vector<T> dat;
    int s;
    int n;

public:
    CoordinateCompression(const std::vector<T>& dat_, int s_ = 0, bool uni = true){
        build(dat_, s_, uni);
    }

    void build(const std::vector<T>& dat_, int s_ = 0, bool uni = true){
        dat = dat_;

        std::sort(dat.begin(), dat.end());
        if(uni){
            dat.erase(std::unique(dat.begin(), dat.end()), dat.end());
        }

        s = s_;

        n = (int)dat.size();

        return;
    }

    int get(T x){
        return (int)(std::lower_bound(dat.begin(), dat.end(), x) - dat.begin()) + s;
    }

    T restore(int k){
        return dat[k - s];
    }

    int size(void){
        return n;
    }
};

template<typename T, typename U>
class SegmentTree{
    int n;
    std::vector<T> node;

    using F = std::function<T(T, T)>;
    using G = std::function<T(T, U)>;

    F f;
    G g;
    T en;

public:
    SegmentTree(int n_, F f_, G g_, T en_){
        init(n_, f_, g_, en_);
    }

    SegmentTree(const std::vector<T>& dat, F f_, G g_, T en_){
        build(dat, f_, g_, en_);
    }

    void init(int n_, F f_, G g_, T en_){
        n = 1;
        while(n < n_){
            n <<= 1;
        }
        f = f_;
        g = g_;
        en = en_;

        node.assign(n << 1, en);

        return;
    }

    void build(const std::vector<T>& dat, F f_, G g_, T en_){
        int n_ = (int)dat.size();

        init(n_, f_, g_, en_);

        for(int i = 0 ; i < n_ ; ++i){
            node[i + n] = dat[i];
        }

        for(int i = n - 1 ; 0 < i ; --i){
            node[i] = f(node[i << 1], node[(i << 1) | 1]);
        }

        return;
    }

    void update(int k, U x){
        k += n;
        node[k] = g(node[k], x);

        while(k >>= 1){
            node[k] = f(node[k << 1], node[(k << 1) | 1]);
        }

        return;
    }

    T get(int l, int r){
        l += n;
        r += n;

        T res = en;
        while(l < r){
            if(l & 1){
                res = f(res, node[l++]);
            }
            l >>= 1;
            if(r & 1){
                res = f(res, node[--r]);
            }
            r >>= 1;
        }

        return res;
    }
};

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    while(std::cin >> n){
        std::vector<long long> a(n);
        for(int i = 0 ; i < n ; ++i){
            std::cin >> a[i];
        }
        a.emplace_back(0LL);

        CoordinateCompression<long long> c(a, -1);
        std::vector<int> id(c.size() - 1);
        for(int i = n - 1 ; i >= 0 ; --i){
            id[c.get(a[i])] = i;
        }
        for(int i = c.size() - 3 ; i >= 0 ; --i){
            id[i] = std::min(id[i], id[i + 1]);
        }

        SegmentTree<long long, long long> sum(c.size() - 1, [](long long l, long long r){ return l + r; },
         [](long long l, long long r){ return l + r; }, 0LL);

        std::vector<long long> ans(n, 0LL);
        int k = n - 1;
        for(int i = c.size() - 2 ; i >= 0 ; --i){
            for( ; k > id[i] ; --k){
                sum.update(c.get(a[k]), 1LL);
            }
            ans[k] += (sum.get(i, c.size() - 1) + 1LL) * (c.restore(i) - c.restore(i - 1));
        }
        for(int i = 0 ; i < n ; ++i){
            std::cout << ans[i] << '\n';
        }
    }

    std::cout << std::flush;

    return 0;
}
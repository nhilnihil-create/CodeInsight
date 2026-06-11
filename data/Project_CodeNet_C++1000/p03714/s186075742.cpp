#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

template<typename T>
class Heap {
private:
    vector<T> heap;
    int lastIndex = 0;
    function<bool(T, T)> compare;

    int up(int x) {
        if(x == 1) {
            return x;
        }
        if(compare(heap[x/2], heap[x])) {
            return x;
        }
        swap(heap[x/2], heap[x]);
        return up(x/2);
    }

    int down(int x) {
        if(x == lastIndex) {
            return x;
        }
        if(x*2 > lastIndex) {
            return x;
        }
        if(x*2 == lastIndex) {
            if(compare(heap[x], heap[x*2])) {
                return x;
            }
            swap(heap[x], heap[x*2]);
            return x*2;
        }

        int i = x*2 + !compare(heap[x*2], heap[x*2 + 1]);

        if(compare(heap[x], heap[i])) {
            return x;
        }
        swap(heap[x], heap[i]);
        return down(i);
    }
public:
    Heap(int size, function<bool(T, T)> compare) {
        lastIndex = 0;
        heap.resize(size + 1);
        this->compare = compare;
    }
    Heap(int size) {
        Heap(size, less<T>());
    }

    void add(T t) {
        lastIndex++;
        heap[lastIndex] = t;
        up(lastIndex);
    }

    void del() {
        swap(heap[1], heap[lastIndex]);
        lastIndex--;
        down(1);
    }

    T get() {
        return heap[1];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    LL N;
    cin >> N;
    vector<LL> a;
    a.resize(3*N);
    REP(i, 3*N) {
        cin >> a[i];
    }

    vector<LL> first;
    vector<LL> second;

    first.resize(N + 1);
    second.resize(N + 1);

    fill(ALL(first), 0);
    fill(ALL(second), 0);

    REP(i, N) {
        first[0] += a[i];
        second[0] += a[3*N - 1 - i];
    }

    Heap<LL> firstHeap(N + 1, less<LL>());
    Heap<LL> secondHeap(N + 1, greater<LL>());

    REP(i, N) {
        firstHeap.add(a[i]);
        secondHeap.add(a[3*N - 1 - i]);
    }

    FOR(i, 1, N + 1) {
        firstHeap.add(a[N + i - 1]);
        first[i] = first[i - 1] + a[N + i - 1] - firstHeap.get();
        firstHeap.del();

        secondHeap.add(a[2*N - i]);
        second[i] = second[i - 1] + a[2*N - i] - secondHeap.get();
        secondHeap.del();
    }

    LL res = -LINF;
    REP(i, N + 1) {
        res = max(first[i] - second[N - i], res);
    }
    cout << res << endl;
    return 0;
}

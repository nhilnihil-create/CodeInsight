#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class T, class Compare>
class SizedHeap
{
public:
    SizedHeap(size_t max_size) : max_size_(max_size), sum_(0) {}

    void Push(const T &val)
    {
        heap_.push(val);
        sum_ += val;

        while (heap_.size() > max_size_) {
            sum_ -= heap_.top();
            heap_.pop();
        }
    }

    T Sum() const { return sum_; }

    size_t Size() const { return heap_.size(); }

protected:
    priority_queue<T, vector<T>, Compare> heap_;
    size_t max_size_;
    T sum_;
};

template <class T>
using MinSizedHeap = SizedHeap<T, greater<T>>;

template <class T>
using MaxSizedHeap = SizedHeap<T, less<T>>;


vector<int64_t> GetPrefixes(const vector<int64_t> &vec, size_t size)
{
    vector<int64_t> prefixes(vec.size(), 0);
    MinSizedHeap<int64_t> heap(size);

    for (size_t i = 0; i < vec.size(); i += 1) {
        heap.Push(vec[i]);
        if (heap.Size() >= size) {
            prefixes[i] = heap.Sum();
        }
    }
    return prefixes;
}

vector<int64_t> GetSuffixes(const vector<int64_t> &vec, size_t size)
{
    vector<int64_t> suffixes(vec.size(), 0);
    MaxSizedHeap<int64_t> heap(size);

    for (int i = vec.size() - 1; i >= 0; i -= 1) {
        heap.Push(vec[i]);
        if (heap.Size() >= size) {
            suffixes[i] = heap.Sum();
        }
    }
    return suffixes;
}

int64_t Solve(const vector<int64_t> &vec)
{
    auto n = vec.size() / 3;
    auto prefixes = GetPrefixes(vec, n);
    auto suffixes = GetSuffixes(vec, n);

    int64_t res = prefixes[n - 1] - suffixes[n];
    for (size_t i = n - 1; i + n < vec.size(); i += 1) {
        res = max(res, prefixes[i] - suffixes[i + 1]);
    }
    return res;
}

int main()
{
    int64_t n;
    cin >> n;

    vector<int64_t> vec(3 * n);
    for (auto &num : vec) {
        cin >> num;
    }

    auto res = Solve(vec);
    cout << res << "\n";

    return 0;
}

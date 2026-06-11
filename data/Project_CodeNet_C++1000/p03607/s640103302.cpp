#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i=0; i<N; ++i) {
        int a;
        cin >> a;
        auto itr = A.find(a);
        if (itr == A.end())
            A.insert(a);
        else
            A.erase(a);
    }
    cout << A.size() << endl;
}

#include <iostream>
#include <set>

int main()
{
    int N;
    std::cin >> N;
    std::set<int> s;
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        if (s.count(A))
            s.erase(A);
        else
            s.insert(A);
    }

    std::cout << s.size() << std::endl;
    return 0;
}
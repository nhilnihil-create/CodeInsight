#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <cmath>
#include <sstream>
#include <numeric>
#include <set>

using namespace std;
long long distance(long long x1, long long y1, long long x2, long long y2);

long long distance(long long x1, long long y1, long long x2, long long y2)
{
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

int main()
{
    long long n, m;
    std::cin >> n >> m;

    std::vector<std::pair<long long, long long>> students;
    for(long long i = 0; i < n; i++)
    {
        long long x, y;
        std::cin >> x >> y;
        students.push_back(std::pair<long long, long long>(x, y));
    }

    std::vector<std::pair<long long, long long>> point;
    for(long long i = 0; i < m; i++)
    {
        long long x, y;
        std::cin >> x >> y;
        point.push_back(std::pair<long long, long long>(x, y));
    }

    for(long long i = 0; i < students.size(); i++)
    {
        long long idx = 0;
        long long max = 10000000000000;
        for(long long j = 0; j < point.size(); j++)
        {
            long long dist = distance(students[i].first, students[i].second, point[j].first, point[j].second);
            if(dist < max)
            {
                max = dist;
                idx = j;
            }
        }
        std::cout << idx +1  << std::endl;
    }
    return EXIT_SUCCESS;
}

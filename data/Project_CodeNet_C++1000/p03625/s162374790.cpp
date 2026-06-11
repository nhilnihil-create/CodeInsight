#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#include<map>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    std::set<long long> sa;
    std::map<long long, long long> ma;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sa.insert(a[i]);
    }

    std::sort(a.begin(), a.end());

    for(auto itr = sa.begin(); itr != sa.end(); itr++) {
        int num = std::upper_bound(a.begin(), a.end(), *itr) - std::lower_bound(a.begin(), a.end(), *itr);
        if(num >= 2) {
          ma.insert(std::make_pair(*itr, num));
        }
    }

    long long ans = 1;
    int cnt2 = 0;
    bool f1 = true;
    bool f2 = false;
    if(ma.size() > 0) {
    for(auto itr = sa.rbegin(); itr != sa.rend(); itr++) {
        if(ma[*itr] >= 4 && f1) {
            ans *= (*itr)*(*itr);
            break;
        } else if(ma[*itr] >= 2) {
            f2 = true;
            f1 = false;
            ans *= *itr;
            cnt2 ++; 
        }

       
        if(cnt2 >= 2) {
           f2 = false;
            break;
        }
    }
    } else {
        ans = 0;
    }

    if (cnt2 < 2 && f2)
    {
        ans = 0;
    }

    std::cout << ans << std::endl;
   
}


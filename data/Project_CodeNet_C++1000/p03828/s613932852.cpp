#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#define mod 1000000007


int main() {
    int n; std::cin >> n;
    std::map<int, int> m; 
    for(int i = 2; i <= n; i++) {
        m.insert(std::make_pair(i, 0));
    }

    for(int i = 2; i <= n; i++)  {
        int div = i;
        for(int j = 2; j * j <= n; j++) {
            while(div%j == 0) {
                m[j] ++;
                div /= j;
            }
        }
        m[div]++;
    }

    long long ans = 1;
    for(auto itr = m.begin(); itr != m.end(); itr++) {
        if(itr->first != 1) {
        ans *= (itr->second+1);
        }
        //std::cout << itr->first << " " << itr->second << std::endl;
        ans %= mod;
    }

    std::cout << ans << std::endl;
}

/*long long fact(int n) {
    std::vector<std::pair<int, int>> a;
    long long r = 1;
    for (int i = 2; i <= n; i++) {

        if(i < 4) {
            r *= 2;
       
        }


        for (int j = 2; j <= i; j++)
        {
            long long tmp = j;
            int index = 0;
            int k = 2;
            while (tmp > 1)
            { 
                if (tmp % k == 0)
                {
                    tmp /= k;
                    index++;
                }
                else
                {
                    k++;
                    r *= index + 1;
                    std::cout << k << " " << index + 1 << "\n";
                    r %= mod;
                }

            }

         
        }
    }

    return r;
}

int main() {
    int n;
    std::cin >> n;

    long long N = fact(n);

    std::cout << N << "\n";
}
*/
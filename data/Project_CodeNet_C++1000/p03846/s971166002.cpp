#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>


using namespace std;

long long modexp(long long x, long long n, long long mod)
{
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return (modexp(x, n / 2, mod) * modexp(x, n / 2, mod)) % mod;
    }
    return (modexp(x, n / 2, mod) * modexp(x, n / 2, mod) * x) % mod;
}



int main()
{
    int n;
    cin >> n;
    
    vector<int> arr;
    int i, ele;
    for (i = 0; i < n; ++i) {
        cin >> ele;
        arr.push_back(ele);
    }
    unordered_map<int, int> m;

    if (n % 2 == 0) {
        for (i = 0; i < n; ++i) {
            m[arr[i]]++;
        }


        unordered_map<int, int>::iterator itr;
        for (itr = m.begin(); itr != m.end(); ++itr) {
            if (itr->first % 2 == 0) {
                cout << "0";
                exit(0);
            }
            if (itr->second != 2) {
                cout << "0";
                exit(0);
            }
            if (itr->first >= n || itr->first < 1) {
                cout << "0";
                exit(0);
            }
        }
        long long ans = modexp(2, n / 2, 1000000000 + 7);

        cout << ans;

        
    }

    else {
        for (i = 0; i < n; ++i) {
            m[arr[i]]++;
        }


        unordered_map<int, int>::iterator itr;
        int contains_zero = 0, count = 0;
        for (itr = m.begin(); itr != m.end(); ++itr) {
            if (itr->first % 2 == 1 &&itr->first!=0) {
                cout << "0";
                exit(0);
            }
            if (itr->second != 2 && itr->first!=0) {
                cout << "0";
                exit(0);
            }
            if (itr->first >= n || itr->first < 0) {
                cout << "0";
                exit(0);
            }
            if (itr->first == 0) {
                contains_zero = 1;
                count = itr->second;
            }
        }
        if (contains_zero != 1 || count != 1) {
            cout << "0";
            exit(0);
        }
        long long ans = modexp(2, (n-1) / 2, 1000000000 + 7);

        cout << ans;

    }
    

}
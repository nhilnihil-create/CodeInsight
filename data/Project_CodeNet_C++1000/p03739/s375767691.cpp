#include <bits/stdc++.h>
using namespace std;

/*
O(N)で解けそうなのはすぐわかる。
偶数/奇数番目を正/負にするか比べるように実装すると間違いにくい。
*/

long first_plus(vector<int> A) {
    long res = 0;
    long sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            while (sum <=0) {
                sum++;
                res++;
            }
        }
        else
        {
            while (sum >=0) {
                sum--;
                res++;
            }
        }
        
    }
    return res;
}

long first_minus(vector<int> A) {
    long res = 0;
    long sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            while (sum >= 0) {
                sum--;
                res++;
            }
        }
        else
        {
            while (sum <= 0) {
                sum++;
                res++;
            }
        }
        
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long res1 = first_plus(A);
    long res2 = first_minus(A);
    cout << min(res1, res2) << endl;
}
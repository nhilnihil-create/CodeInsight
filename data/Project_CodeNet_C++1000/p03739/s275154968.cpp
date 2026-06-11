#include <bits/stdc++.h>
using namespace std;


// long solve(vector<long> A) {
//     long res = 0;
//     long sum = A[0];
//     for (int i = 1; i < A.size(); i++)
//     {
//         if (sum > 0) {
//             sum += A[i];
//             while (sum >= 0) {
//                 res++;
//                 sum--;
//             }
//         }
//         else if (sum < 0)
//         {
//             sum += A[i];
//             while (sum <= 0) {
//                 res++;
//                 sum++;
//             }
//         }
//     }
//     return res;
// }

// int main() {
//     int N;
//     cin >> N;

//     vector<long> A(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> A[i];
//     }

//     long res;
//     if (A[0] != 0)
//     {
//         res = solve(A);
//         cout << res << endl;
//     }
//     else
//     {
//         long res_first_plus=1, res_first_minus=1;
//         A[0] = 1;
//         res_first_plus += solve(A);

//         A[0] = -1;
//         res_first_minus += solve(A);
//         res = min(res_first_plus, res_first_minus);
//         cout << res << endl;
//     }
// }

long first_plus(vector<long> &A) {
    long sum = 0;
    long res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            while (sum < 1)
            {
                sum++;
                res++;
            }
        }
        else
        {
            while (sum > -1) {
                sum--;
                res++;
            }
        }
    }
    return res;
}

long first_minus(vector<long> &A) {
    long sum = 0;
    long res = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (i % 2 == 0)
        {
            while (sum > -1) {
                sum--;
                res++;
            }
        }
        else
        {
            while (sum < 1)
            {
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

    vector<long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << min(first_plus(A), first_minus(A)) << endl;
}
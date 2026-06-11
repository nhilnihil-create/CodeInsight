#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

// int main(void)
// {
//     int N;
//     cin >> N;

//     vector<int> a(N);
//     int four = 0;
//     int two = 0;
//     int other = 0;
//     for (int i = 0; i < N; i++)
//     {
//         int num;
//         cin >> num;
//         if (num % 4 == 0)
//         {
//             four++;
//         }
//         else if (num % 2 == 0)
//         {
//             two++;
//         }
//         else
//         {
//             other++;
//         }
//     }

//     string ans;
//     if (two == 0)
//     {
//         if (other <= four + 1)
//         {
//             ans = "Yes";
//         }
//         else
//         {
//             ans = "No";
//         }
//     }
//     else
//     {
//         if (other <= four)
//         {
//             ans = "Yes";
//         }
//         else
//         {
//             ans = "No";
//         }
//     }
//     cout << ans << endl;
// }

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    int four = 0;
    int two = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        // 4の倍数
        if (a[i] % 4 == 0)
        {
            four++;
        }
        else if (a[i] % 2 == 0)
        {
            two++;
        }
    }
    // printf("four = %d, two = %d\n", four, two);

    string ans;
    int sum;
    if (two % 2 == 0)
    {
        sum = four * 4 + two * 2;
    }
    else
    {
        sum = four * 4 + (two - 1) * 2;
    }
    // printf("left = %d, sum = %d\n", (N / 2) * 4, sum);
    if ((N / 2) * 4 <= sum)
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }
    cout << ans << endl;
    return (0);
}
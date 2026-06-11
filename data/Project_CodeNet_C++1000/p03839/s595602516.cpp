#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 123456;
int n, k, a[MAX_N];
long long partialk[MAX_N], positive_sum[MAX_N];


int main() {

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (i == 0)
            positive_sum[i] = max(a[i], 0);

        else
            positive_sum[i] = positive_sum[i - 1] + max(a[i], 0);

//        cout << positive_sum[i] << " ";
    }

//    cout << endl;

    long long max_sum, black_k, white_k;

    for (int i = 0; i < k; ++i)

        partialk[0] += a[i];


    black_k = partialk[0] + positive_sum[n - 1] - positive_sum[k - 1];

    white_k = positive_sum[n - 1] - positive_sum[k - 1];


    max_sum = max(black_k, white_k);


//    printf("black k :: %d = partialk[0] :: %d + positive sum[n - 1] :: %d - positive sum[k - 1] :: %d\n",
//           black_k, partialk[0], positive_sum[n - 1], positive_sum[k - 1]);
//
//    cout << endl;
//
//    printf("white k :: %d = positive sum[n - 1] :: %d + positive sum[k - 1] :: %d\n",
//           white_k, positive_sum[n - 1], positive_sum[k - 1]);
//
//    cout << endl;


//    printf("i :: %d black k :: %d white k :: %d max sum :: %d\n", 0, black_k, white_k, max_sum);
//    cout << "partialk :: " << partialk[0] << " ";


    for (int i = k; i < n; ++i) {

        partialk[i - k + 1] = partialk[i - k] + a[i] - a[i - k];


        black_k = partialk[i - k + 1] + positive_sum[n - 1] - positive_sum[i] + positive_sum[i - k];

        white_k = positive_sum[n - 1] - positive_sum[i] + positive_sum[i - k];


//        printf("black k :: %d = partialk[i - k + 1] :: %d + positive sum[n - 1] :: %d - positive sum[i] :: %d + positive sum[i - k] :: %d\n",
//                black_k, partialk[i- k + 1], positive_sum[n - 1], positive_sum[i], positive_sum[i - k]);
//
//        cout << endl;
//
//        printf("white k :: %d = positive sum[n - 1] :: %d - positive sum[i] :: %d + positive sum[i - k] :: %d\n",
//                white_k, positive_sum[n - 1], positive_sum[i], positive_sum[i - k]);
//
//        cout << endl;


        if (max(black_k, white_k) > max_sum)
            max_sum = max(black_k, white_k);

//        printf("i :: %d black k :: %d white k :: %d max sum :: %d\n", i, black_k, white_k, max_sum);

//        cout << partialk[i - k + 1] << " ";

//       printf("partialk i - k :: %d a[i] :: %d a[i - k] :: %d \n", partialk[i - k], a[i], a[i - k]);

    }
//    cout << endl;

    cout << max_sum << endl;
    return 0;
}

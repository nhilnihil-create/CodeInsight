#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    using namespace std;

    long long H, W;
    cin >> H >> W;

    if (H %3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

//     long long s1 = 0, s2 = 0, s3 = 0;
//     if (H < W) {
//         long long w1 = (W/3 - 1) + W%3;
// //        cout << "w1:" << w1 << endl;
//         s1 = H * w1;
//         if (H < W - w1) {
//             long long w2 = (W - w1)/2;
// //            cout << "w2:" << w2 << endl;
//             s2 = H * w2;
//             s3 = H * (W - w1 - w2);
//         } else {
//             long long h2 = H/2;
// //            cout << "h2:" << h2 << endl;
//             s2 = h2 * (W - w1);
//             s3 = (H - h2) * (W - w1);
//         }
//     } else {
//         long long h1 = H/3 - 1 + H%3;
// //        cout << "h1:" << h1 << endl;
//         s1 = W * h1;
//         if (W < H - h1) {
//             long long h2 = (H - h1)/2;
// //            cout << "h2:" << h2 << endl;
//             s2 = W * h2;
//             s3 = W * (H - h1 - h2);
//         } else {
//             long long w2 = W/2;
// //            cout << "w2:" << w2 << endl;
//             s2 = w2 * (H - h1);
//             s3 = (W - w2) * (H - h1);
//         }
//     }

//     long long smin = std::min({s1, s2, s3});
//     long long smax = std::max({s1, s2, s3});

//     cout << smax - smin << endl;

    // 全探索
    // long long result = std::numeric_limits<long long>::max();
    // long long s1 = 0, s2 = 0, s3 = 0;
    // for (long long i=1; i<H/2; i++) {
    //     s1 = i * W;
    //     for (long long j=i+1; j<H; j++) {
    //         s2 = (j - i) * W;
    //         s3 = (H - j) * W;

    //         long long smin = std::min({s1, s2, s3});
    //         long long smax = std::max({s1, s2, s3});
    //         result = std::min({smax - smin, result});
    //     }
 
    //     long long h1 = std::max({i, (H-i)});
    //     for (long long k=1; k<W; k++) {
    //         s2 = k * h1;
    //         s3 = (W - k) * h1;

    //         long long smin = std::min({s1, s2, s3});
    //         long long smax = std::max({s1, s2, s3});
    //         result = std::min({smax - smin, result});
    //     }
    // }

    // for (long long i=1; i<W/2; i++) {
    //     s1 = i * H;
    //     for (long long j=i+1; j<W; j++) {
    //         s2 = (j - i) * H;
    //         s3 = (W - j) * H;

    //         long long smin = std::min({s1, s2, s3});
    //         long long smax = std::max({s1, s2, s3});
    //         result = std::min({smax - smin, result});
    //     }

    //     long long w1 = std::max({i, (W-i)});
    //     for (long long k=1; k<H; k++) {
    //         s2 = k * w1;
    //         s3 = (H - k) * w1;

    //         long long smin = std::min({s1, s2, s3});
    //         long long smax = std::max({s1, s2, s3});
    //         result = std::min({smax - smin, result});
    //     }
    // }

    long long result = std::numeric_limits<long long>::max();
    long long s1 = 0, s2 = 0, s3 = 0;
    long long smin, smax;
    for (long long i=1; i<H/2+1; i++) {
        s1 = i * W;

        long long h2 = (H-i)/2;
        long long h3 = H-(i+h2);
        s2 = h2 * W;
        s3 = h3 * W;
        smin = std::min({s1, s2, s3});
        smax = std::max({s1, s2, s3});
        result = std::min({smax - smin, result});
        // for (long long j=i+1; j<H; j++) {
        //     s2 = (j - i) * W;
        //     s3 = (H - j) * W;

        //     long long smin = std::min({s1, s2, s3});
        //     long long smax = std::max({s1, s2, s3});
        //     result = std::min({smax - smin, result});
        // }

        long long h1 = std::max({i, (H-i)});
        long long w1 = W/2;
        long long w2 = W - w1;
        s2 = w1 * h1;
        s3 = w2 * h1;
        smin = std::min({s1, s2, s3});
        smax = std::max({s1, s2, s3});
        result = std::min({smax - smin, result});
        // for (long long k=1; k<W; k++) {
        //     s2 = k * h1;
        //     s3 = (W - k) * h1;

        //     long long smin = std::min({s1, s2, s3});
        //     long long smax = std::max({s1, s2, s3});
        //     result = std::min({smax - smin, result});
        // }
    }

//    cout << "W/2:" << W/2 << endl;

    for (long long i=1; i<W/2+1; i++) {
        s1 = i * H;

//        cout << "s1:" << s1 << endl;

        long long w2 = (W-i)/2;
        long long w3 = W-(i+w2);
        s2 = w2 * H;
        s3 = w3 * H;
        smin = std::min({s1, s2, s3});
        smax = std::max({s1, s2, s3});
        result = std::min({smax - smin, result});
//        cout << "s2:" << s2 << endl;
//        cout << "s3:" << s3 << endl;

        // for (long long j=i+1; j<W; j++) {
        //     s2 = (j - i) * H;
        //     s3 = (W - j) * H;

        //     long long smin = std::min({s1, s2, s3});
        //     long long smax = std::max({s1, s2, s3});
        //     result = std::min({smax - smin, result});
        // }

        long long w1 = std::max({i, (W-i)});
        long long h1 = H/2;
        long long h2 = H - h1;
        s2 = h1 * w1;
        s3 = h2 * w1;
        smin = std::min({s1, s2, s3});
        smax = std::max({s1, s2, s3});
        result = std::min({smax - smin, result});
//        cout << "s2:" << s2 << endl;
//        cout << "s3:" << s3 << endl;

        // for (long long k=1; k<H; k++) {
        //     s2 = k * w1;
        //     s3 = (H - k) * w1;

        //     long long smin = std::min({s1, s2, s3});
        //     long long smax = std::max({s1, s2, s3});
        //     result = std::min({smax - smin, result});
        // }
    }

    cout << result << endl;
    
    return 0;
}
#include <iostream>

long max(long T, long A, long min_pole[])
{
    long right = min_pole[0] / T;
    if (min_pole[0] % T != 0) right++;

    long left = min_pole[1] / A;
    if (min_pole[1] % A != 0) left++;

    return right >= left? right : left; 
}

int main()
{
    int N;
    std::cin >> N;

    long T[N];
    long A[N];
    int i;
    for (i = 0; i < N; i ++) {
        std::cin >> T[i] >> A[i];
    }

    long min_pole[2] = {1, 1};
    for (i = 0; i < N; i++) {
        if (T[i] < min_pole[0] || A[i] < min_pole[1]) {
            long n = max(T[i], A[i], min_pole);
            min_pole[0] = T[i] * n;
            min_pole[1] = A[i] * n;
        } else {
            min_pole[0] = T[i];
            min_pole[1] = A[i];
        }
    }
    
    std::cout << min_pole[0] + min_pole[1];

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

bool test(int hi[], int N, int A, int B, int times) {
    int diff = A - B;
    long long power = B * (long long)times;
    long long count = 0;
    for (int i=0; i<N; i++) {
        long long tough = hi[i] - power;
        if (tough > 0) {
            count += (tough + diff - 1) / diff;
        }
    }
    if (count <= times) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    int hi[N];
    for (int i=0; i<N; i++) {
        scanf("%d", &hi[i]);
    }

    int left = 1;
    int right = 1000000000;

    while (true) {
        if (left == right) {
            break;
        }
        int mid = (left + right) / 2;
        if (test(hi, N, A, B, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", left);

    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; scanf("%d", &N);

    vector<int> vec(N);
    for(int i=0; i<N; i++) {
        scanf("%d", &vec[i]);
    }
    sort(vec.rbegin(), vec.rend());
    vec.push_back(0);

    int idx = 0;
    while(idx < N && idx < vec[idx]) idx++;
    idx--;

    // printf("idx = %d\n", idx);

    int vl = vec[idx] - idx;

    int height = idx;
    while(idx < N && height < vec[idx + 1]) idx++;
    int vr = idx - height + 1;

    fprintf(stderr, "vl = %d, vr = %d\n", vl, vr);

    if(vl % 2 == 0 || vr % 2 == 0) printf("First\n");
    else printf("Second\n");
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int n , a[100005];
int main() {
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i) scanf("%d" , a + i);
    sort(a + 1 , a + 1 + n , greater<int>());
    for(int i = 1 ; i <= n ; ++i) if(a[i + 1] < i + 1) {
        int j = i;
        while(a[j + 1] == i) ++j;
        if((a[i] - i)&1 || (j - i)&1) return puts("First") & 0;
        else return puts("Second") & 0;
    }
}
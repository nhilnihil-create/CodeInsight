#include <cstdio>

using namespace std;

char s[2];

int get(long long x) {
    printf("? %lld\n", x);
    fflush(stdout);
    
    scanf("%s", s);
    
    if (s[0] == 'Y') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int f = 1;
    long long ans = 0;
    
    while (1) {
        int l, r, m;
        
        l = -1, r = 9;
        if (ans == 0) l = 0;
        m = (l + r) / 2;
        
        while (r - l > 1) {
            long long x = ans * 10 + m;
            
            while (x < 1e10) x = x * 10 + 9;
            
            if (get(x) == 1) {
                r = m;
                m = (l + r) / 2;
            } else {
                l = m;
                m = (l + r) / 2;
            }
        }
        
        if (ans > 0 && r == 0) {
            long long x = (ans - 1) * 10 + 9;
            
            if (get(x) == f) {
                printf("! %lld\n", ans);
                return 0;
            }
        }
        
        if (r > 1) f = 0;
        
        ans = ans * 10 + r;
    }
    
    return 0;
}

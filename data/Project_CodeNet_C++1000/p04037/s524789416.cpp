#include <bits/stdc++.h>

using namespace std;


namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    inline void readll(long long int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};

using namespace fastIO;

const int maxn = 1e5 + 5;

int arr[maxn];

bool cmp(int a, int b) { return a > b; }

int main()
{
    int n;
    //read(n);
    cin >> n;

    for(int i = 1; i <= n; i++)
        //read(arr[i]);
        cin >> arr[i];

    sort(arr + 1, arr + 1 + n, cmp);

     for (int i = 1; i <= n; i++)
        if (i + 1 > arr[i + 1])
        {
            int k = 0;
            while(arr[k + i + 1] == i) k++;
            if (((arr[i] - i) & 1) || (k & 1)) puts("First");
            else puts("Second");
            break;
        }

    return 0;
}

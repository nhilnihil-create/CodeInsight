#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e5 + 100;

int a[N];
int sl[N], sr[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    vector <int> st;
    st.push_back(0);
    
    for (int i = 1; i <= n; i++)
    {
        while (a[i] < a[st.back()])
            st.pop_back();
        sl[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    st.push_back(n + 1);

    for (int i = n; i >= 1; i--)
    {
        while (a[i] < a[st.back()])
            st.pop_back();
        sr[i] = st.back();
        st.push_back(i);
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        //eprintf("[%d, %d, %d] %d\n", sl[i], i, sr[i], a[i]);
        ans += (sr[i] - i) * 1LL * (i - sl[i]) * 1LL * a[i];
    }

    printf("%lld\n", ans);

	return 0;
}



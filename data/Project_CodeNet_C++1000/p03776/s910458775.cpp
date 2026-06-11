#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;

int n, a, b;
vector<long> v;

struct choice {
    long sum;
    double avg;
    map<long, int> cnt;
};

choice c[50];

int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        long x;
        scanf("%ld", &x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end(), [](const long &l1, const long &l2)->bool {
        return l1 > l2;
    });
    
    c[0].cnt[v[0]]++;
    c[0].sum = v[0];
    c[0].avg = v[0];
    for (int i = 1; i < n; i++) {
        c[i].cnt = map<long, int>(c[i - 1].cnt);
        c[i].cnt[v[i]]++;
        c[i].sum = c[i - 1].sum + v[i];
        c[i].avg = static_cast<double>(c[i].sum) / (i + 1);
    }

    map<long, int> &m = c[n - 1].cnt;
    
    long ans = 0;
    double am = c[a - 1].avg;
    for (int i = a - 1; i < b; i++) {
        if (c[i].sum * a != c[a - 1].sum * (i + 1)) break;
        long ans1 = 1;
        for (auto &j : c[i].cnt) {
            for (int k = 0; k < j.second; k++) {
                ans1 = ans1 * (m[j.first] - k) / (k + 1);
            }
        }
        ans += ans1;
    }

    printf("%lf\n", am);
    printf("%ld\n", ans);
    return 0;
}

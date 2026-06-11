#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
int p;
vector<int> ans;

int main() {
    cin>>N;
    for(p = 42; p >= 0; p--) {
        if(N >= (1LL << p) - 1) break;
    }
    for(int i = 1; i <= p; i++) ans.push_back(i);
    N -= (1LL << p) - 1;
    int v = ++p;
    for(int i = p; i >= 0; i--) {
        if(N < (1LL << i)) continue;
        ans.push_back(v++);
        for(int j = ans.size() - 1; j >= i + 1; j--) {
            int tmp = ans[j];
            ans[j] = ans[j - 1];
            ans[j - 1] = tmp;
        }
        N -= (1LL << i);
    }
    for(int i = 1; i <= 100; i++) ans.push_back(i);
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
}

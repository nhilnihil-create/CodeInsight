#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int cnt[100001];
vector<pair<int, int>> mod[100001];

bool compare(pair<int, int> x, pair<int, int> y)
{
    if (cnt[x.first] % 2 && cnt[x.first] == x.second)
        return false;
    if (cnt[y.first] % 2 && cnt[y.first] == y.second)
        return true;
    if (cnt[x.first] == cnt[y.first])
        return x.first > y.first;
    return cnt[x.first] > cnt[y.first];
}

int main(void)
{
    int N, M, X;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> X;
        cnt[X]++;
        mod[X % M].push_back(pair<int, int>(X, cnt[X]));
    }

    for (int i = 0; i < M; i++)
        sort(mod[i].begin(), mod[i].end(), compare);

#ifdef DEBUG
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        for (int j = 0; j < mod[i].size(); j++)
            cout << mod[i][j].first << " ";
        cout << endl;
    }
#endif

    int res = mod[0].size() / 2;
    if (M % 2 == 0) {
        res += mod[M / 2].size() / 2;
        mod[M / 2].clear();
    }

    for (int i = 1; i <= M / 2; i++) {
        while(mod[i].size() && mod[M - i].size()) {
#ifdef DEBUG
            cout << mod[i][mod[i].size() - 1].first << " " << mod[M - i][mod[M - i].size() - 1].first << endl;
#endif
            mod[i].pop_back();
            mod[M - i].pop_back();
            res++;
        }
    }

#ifdef DEBUG
    for (int i = 0; i < M; i++) {
        cout << i << ": ";
        for (int j = 0; j < mod[i].size(); j++)
            cout << mod[i][j].first << " ";
        cout << endl;
    }
#endif

    for (int i = 1; i < M; i++) {
        if (mod[i].size() < 2)
            continue;
        for (int j = 0; j < mod[i].size() - 1; j++) {
            if (mod[i][j].first == mod[i][j + 1].first) {
#ifdef DEBUG
                cout << mod[i][j].first << " " << mod[i][j + 1].first << endl;
#endif
                j++;
                res++;
            }
        }
    }

    cout << res << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    pair<int, int> component[n + 1];
    vector<int> road[n + 1], rail[n + 1];
    for (int i = 0, p, q; i < k; i++) {
        cin >> p >> q;
        road[p].emplace_back(q);
        road[q].emplace_back(p);
    }
    for (int i = 0, p, q; i < l; i++) {
        cin >> p >> q;
        rail[p].emplace_back(q);
        rail[q].emplace_back(p);
    }
    vector<bool> visited(n + 1);
    for (int i = 1, count = 0; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            stack<int> stack;
            stack.emplace(i);
            do {
                auto top = stack.top();
                component[top].first = count;
                stack.pop();
                for (int j : road[top]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        stack.emplace(j);
                    }
                }
            } while(!stack.empty());
            count++;
        }
    }
    fill(begin(visited), end(visited), false);
    for (int i = 1, count = 0; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            stack<int> stack;
            stack.emplace(i);
            do {
                auto top = stack.top();
                component[top].second = count;
                stack.pop();
                for (int j : rail[top]) {
                    if (!visited[j]) {
                        visited[j] = true;
                        stack.emplace(j);
                    }
                }
            } while(!stack.empty());
            count++;
        }
    }
    map<pair<int, int>, int> count;
    for (int i = 1; i <= n; i++) {
        count[component[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << count[component[i]] << ' ';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> graph[n];
    int result = n;
    for (int a, b; cin >> a >> b; ) {
        graph[a - 1].emplace_back(b - 1);
        graph[b - 1].emplace_back(a - 1);
    }
    if (k % 2 == 0) {
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n);
            visited[i] = true;
            queue<int> queue;
            queue.emplace(i);
            int current = 0, dist = 0;
            do {
                for (auto size = queue.size(); size > 0; size--) {
                    auto front = queue.front();
                    if (dist > k / 2) {
                        current++;
                    }
                    queue.pop();
                    for (auto j : graph[front]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            queue.emplace(j);
                        }
                    }
                }
                dist++;
            } while (!queue.empty());
            result = min(result, current);
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                vector<bool> visited(n);
                visited[i] = true;
                visited[j] = true;
                queue<int> queue;
                queue.emplace(i);
                queue.emplace(j);
                int current = 0, dist = 0;
                do {
                    for (auto size = queue.size(); size > 0; size--) {
                        auto front = queue.front();
                        if (dist > k / 2) {
                            current++;
                        }
                        queue.pop();
                        for (auto j : graph[front]) {
                            if (!visited[j]) {
                                visited[j] = true;
                                queue.emplace(j);
                            }
                        }
                    }
                    dist++;
                } while (!queue.empty());
                result = min(result, current);
            }
        }
    }
    cout << result;
    return 0;
}
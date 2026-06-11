#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void DFS(int vert, vector<vector<int>>& sons, vector<int>& hight) {
    for (const auto & son: sons[vert]) {
        DFS(son, sons, hight);
    }
    sort(sons[vert].begin(), sons[vert].end(), [&](int a, int b) {
         return hight[a] < hight[b];});
    for (const auto & x: sons[vert]) {
        hight[vert] = max(hight[vert], hight[x]) + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> numb(n - 1);
    for (auto & x: numb) {
        cin >> x;
    }
    vector<vector<int>> sons(n);
    for (int i = 0; i < n - 1; ++i) {
        sons[numb[i] - 1].push_back(i + 1);
    }
    vector<int> hight(n);
    DFS(0, sons, hight);
    cout << hight[0];




    return 0;
}

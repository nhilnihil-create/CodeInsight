#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int cities, const vector<vector<int> > &connectionList) {
    vector<int> indices(cities);
    for (int city = 0, component = 1; city < cities; city++) {
        if (indices[city]) {
            continue;
        }
        indices[city] = component;
        queue<int> q;
        q.push(city);
        while (!q.empty()) {
            int curCity = q.front();
            q.pop();
            for (auto nextCity: connectionList[curCity]) {
                if (!indices[nextCity]) {
                    indices[nextCity] = component;
                    q.push(nextCity);
                }
            }
        }
        component++;
    }
    return indices;
}

vector<vector<int> > transformConnections(int cities, const vector<pair<int, int> > &connections) {
    vector<vector<int> > connectionList(cities);
    for (auto connection: connections) {
        connectionList[connection.first].push_back(connection.second);
        connectionList[connection.second].push_back(connection.first);
    }
    return connectionList;
}

vector<int> connectedCities(int cities, const vector<pair<int, int> > &roads, const vector<pair<int, int> > &rails) {
    vector<vector<int> > listRoads = transformConnections(cities, roads);
    vector<vector<int> > listRails = transformConnections(cities, rails);
    vector<int> indicesRoads = bfs(cities, listRoads);
    vector<int> indicesRails = bfs(cities, listRails);
    unordered_map<long long, int> pairIndices;
    for (int city = 0; city < cities; city++) {
        long long pairIndex = ((long long) indicesRoads[city]) * cities + indicesRails[city];
        pairIndices[pairIndex]++;
    }
    vector<int> result(cities);
    for (int city = 0; city < cities; city++) {
        long long pairIndex = ((long long) indicesRoads[city]) * cities + indicesRails[city];
        result[city] = pairIndices[pairIndex];
    }
    return result;
}

void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<pair<int, int> > roads(k), rails(l);
	for (auto &p: roads) {
		cin >> p.first >> p.second;
		p.first--;
		p.second--;
	}
	for (auto &p: rails) {
		cin >> p.first >> p.second;
		p.first--;
		p.second--;
	}
	vector<int> res = connectedCities(n, roads, rails);
	for (auto v: res) {
		cout << v << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
}

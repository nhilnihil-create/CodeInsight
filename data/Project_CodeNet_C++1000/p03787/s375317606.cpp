#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000, INDEX = 1;

struct Component {
    int numberOfVertices = 0;

    bool isOddCycle, isAlone;

    Component() {
        numberOfVertices = 0;

        isOddCycle = false, isAlone = true;
    }
};

int n, m;

list<int> edge[MAX_N + INDEX];

bool isUsed[MAX_N + INDEX];

int parity[MAX_N + INDEX];

Component components[MAX_N + INDEX];

void DFS(int c, int v, int parityv) {
    isUsed[v] = true;

    parity[v] = parityv;

    components[c].numberOfVertices++;

    for (auto u: edge[v]) {
        components[c].isAlone = false;

        if (!isUsed[u]) {
            DFS(c, u, (parityv + 1) % 2);
        } else {
            if (parity[u] == parity[v]) {
                components[c].isOddCycle = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;

        cin >> u >> v;

        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int numberOfComponents = 0;
    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            components[++numberOfComponents] = Component();

            DFS(numberOfComponents, i, 0);
        }
    }

    int numberOfOddComponents = 0, numberOfAloneComponents = 0;
    for (int i = 1; i <= numberOfComponents; i++) {
        if (components[i].isAlone) {
            numberOfAloneComponents++;
        }

        if (components[i].isOddCycle) {
            numberOfOddComponents++;
        }
    }

//    int ans = 0;
//    for (int i = 1; i <= numberOfComponents; i++) {
//        for (int j = 1; j <= numberOfComponents; j++) {
//            if (components[i].isAlone || components[j].isAlone) {
//                ans += components[i].numberOfVertices * components[j].numberOfVertices;
//            } else {
//                if (components[i].isOddCycle || components[j].isOddCycle) {
//                    ans += 1;
//                } else {
//                    ans += 2;
//                }
//            }
//        }
//    }

    long long ans = 0;
    for (int i = 1; i <= numberOfComponents; i++) {
        if (components[i].isAlone) {
            ans += n;
        }

        if (components[i].isOddCycle) {
            ans += numberOfComponents + (components[i].numberOfVertices - 1) * numberOfAloneComponents;
        }

        if (!(components[i].isAlone || components[i].isOddCycle)) {
            ans += (numberOfComponents - numberOfAloneComponents) + (numberOfComponents - numberOfOddComponents) + (components[i].numberOfVertices - 1) * numberOfAloneComponents;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

/*
6 7
1 3
1 4
2 3
1 5
3 5
2 4
5 6
*/

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;

const int INF=0x3f3f3f3f;
const int N=1e5+5;

int n, m;
vector <int> ls[N];
int bio[N], prvi=1;
vector <int> sol;
deque <int> Q;

#define deg(x) ls[x].size()

//int dfs1(int node) {
//    bio[node]=1;
//    int flag=1, res=0;
//    for (int i=0; i<deg(node); ++i) {
//        int sus=ls[node][i];
//        printf("node==%d, sus: %d, bio: %d\n", node, sus, bio[sus]);
//        system("pause");
//        if (!bio[sus]) {
//            int pom=dfs1(sus);
//            if (pom) {
//                sol.pb(node);
//                res=1;
//            }
//            flag=0;
//        }
//    }
//    if (flag && prvi) {
//        sol.pb(node);
//        prvi=0;
//        return 1;
//    }
//    return res;
//}


void load() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m;++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ls[a].pb(b);
        ls[b].pb(a);
    }
}

void solve() {
    Q.push_back(1);
    bio[1]=1;
    while (1) {
        int node=Q.front(), fl=0;
        if (bio[node]==2) {
            node=Q.back();
            fl=1;
            if (node==1) bio[node]++;
            //printf("tuuuuuuuu node = %d\n");
        }
        if (bio[node]==2 || bio[node]>3) break;
        if (bio[node]<=1) bio[node]=2;
        for (int sus:ls[node]) {
            int z=0;
            if (!bio[sus]) {
                //printf("node == %d, sus == %d, fl == %d\n", node, sus, fl);
                if (fl) Q.push_back(sus);
                else Q.push_front(sus);
                bio[sus]=1; break;
            }
        }
    }
    printf("%d\n", Q.size());
    while (!Q.empty()) {
        printf("%d ", Q.front());
        Q.pop_front();
    }
}

int main() {
    load();
    solve();
    return 0;
}

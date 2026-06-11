#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

vector <int> edges[100000];
int color[100000];
int order[100000];
bool used[100000];
vector <pair <int, pair<int, int> > >ord_v_c[11];
int main(){ 
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a;
        int b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int v;
        int d;
        int c;
        cin >> v >> d >> c;
        ord_v_c[d].push_back(make_pair(i, make_pair(v - 1, c)));
    }

    for(int i = 0; i < N; i++){
        color[i] = 0;
        order[i] = -1;
    }

    for(int i = 10; i >= 0; i--){
        sort(ord_v_c[i].begin(), ord_v_c[i].end());
        for(int j = 0; j < N; j++){
            used[j] = false;
        }
        for(int j = ord_v_c[i].size() - 1; j >= 0; j--){
            auto tmp = ord_v_c[i][j];
            int cur_ord = tmp.first;
            int cur_v = tmp.second.first;
            int cur_c = tmp.second.second;
            if(used[cur_v]){
                continue;
            }
            if(cur_ord > order[cur_v]){
                order[cur_v] = cur_ord;
                color[cur_v] = cur_c;
            }
            used[cur_v] = true;
            if(i > 0){
                for(int k = 0; k < edges[cur_v].size(); k++){
                    int next_v = edges[cur_v][k];
                    if(!used[next_v]){
                        ord_v_c[i - 1].push_back(make_pair(cur_ord, make_pair(next_v, cur_c)));
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << color[i] << endl;
    }
    return 0;
}
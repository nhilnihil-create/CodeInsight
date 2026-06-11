#include <iostream>
#include <vector>
#include <deque>

template <class T>
using Table = std::vector<std::vector<T> >;

class Edge{
public:
    int from, to;
    long long cost;
    Edge(): from(0), to(0), cost(0){}
    Edge(int u, int v, long long w): from(u), to(v), cost(w){}
    ~Edge(){}
    bool operator<(const Edge &e)const{
        return cost < e.cost;
    }
};

void search(Table<int> &to_list, std::vector<bool> &visited,
        std::deque<int> &path)
{
    int tmp = 0;
    path.push_front(tmp);
    while(1){
        visited[tmp] = true;
        if(to_list[tmp].empty()) break;

        bool is_end = true;
        for(int v: to_list[tmp]){
            if(visited[v] == false){
                path.push_back(v); tmp = v;
                is_end = false; break;
            }
        }
        if(is_end == true) break;
    }

    tmp = 0;
    for(int& v: to_list[0]){
        if(visited[v] == false) tmp = v;
        // printf("v=%d\n", v);
    }
    if(tmp == 0) return;
    path.push_front(tmp);
    // printf("tmp=%d\n", tmp);

    while(1){
        visited[tmp] = true;
        if(to_list[tmp].empty()) break;

        bool is_end = true;
        for(int v: to_list[tmp]){
            if(visited[v] == false){
                path.push_front(v); tmp = v;
                is_end = false; break;
            }
        }
        if(is_end == true) break;
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Table<int> to_list(N);
    for(int i=0; i<M; i++){
        int u, v;
        scanf(" %d %d", &u, &v);
        u--; v--;
        to_list[u].push_back(v);
        to_list[v].push_back(u);
    }

    std::vector<bool> visited(N, false);
    std::deque<int> path;
    search(to_list, visited, path);

    printf("%lu\n", path.size());
    for(int& u: path) printf("%d ", u+1);
    printf("\n");
}
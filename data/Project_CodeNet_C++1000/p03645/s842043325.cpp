#include<iostream>
#include<vector>
#include<string>

int main(){
    int n, m; // 行きたいのは島n-1
    std::cin >> n >> m;
    std::vector<std::vector<int>> ship(n);
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        ship[a].push_back(b);
        ship[b].push_back(a);
    }

    int now = 0;
    for(int i = 0; i < ship[now].size(); i++){
        int next = ship[now][i];
        for(int j = 0; j < ship[next].size(); j++){
            int target = ship[next][j];
            if(target == n - 1){
                std::cout << "POSSIBLE" << std::endl;
                return 0;
            }
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}

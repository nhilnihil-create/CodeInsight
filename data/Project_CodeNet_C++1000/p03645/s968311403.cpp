#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long N,M;
    std::cin >> N >> M;
    std::vector<std::vector<long> > ship(200000+1);
    for(long i=0; i<M; i++){
        long a,b;
        std::cin >> a >> b;
        ship[a].push_back(b);
    }
    bool flag=0;
    std::vector<long> root;
    for(long i=0; i<ship[1].size();i++){
        root.push_back(ship[1][i]);
    }
    for(long i=0; i<root.size(); i++){
        for(long j=0; j<ship[root[i]].size(); j++){
            if(ship[root[i]][j]==N){
                flag=1;
                break;
            }
        }
    }
    if(flag){
        std::cout << "POSSIBLE" << std::endl;
    }else{
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}
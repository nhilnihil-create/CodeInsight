#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <regex>
#include <initializer_list>
#define DBL_MIN 0.000000000000001

#define A_P(n,a,d) (n/2)*(2*a + (n-1)*d)
using namespace std;

//ちゃんとlong型でやってる？

int main(void){
    int M,N;
    cin >> N >> M;

    
    int cnt =0; 
    
    vector<pair<int, int>> graph;
    vector<long int> list(N,INT32_MAX);
    list[0] = 0;
    for(int i =0; i < M; i++){
        int a,b;
        cin >> a >> b;
        auto tmp =  pair<int,int>(a,b);
        graph.push_back(tmp);
    }

    sort(graph.begin(), graph.end());

    for(int i = 0; i < M; i++){
        int a = graph[i].first;
        int b = graph[i].second;
 
        if(list[b-1] > list[a-1] + 1)       
            list[b-1] = list[a-1] + 1;
    }

    if(list[N-1] <= 2){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
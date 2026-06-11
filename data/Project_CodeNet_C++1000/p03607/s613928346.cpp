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
using namespace std;


int main(void){
    map<int,int> table;
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(table[tmp] == 0){
            table[tmp] = 1;
            cnt++;
        }else{
            table[tmp] = 0;
            cnt--;
        }
    }
    cout << cnt << endl;
    return 0;
    
}   
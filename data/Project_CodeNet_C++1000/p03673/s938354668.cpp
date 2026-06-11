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
    vector<int> table;
    int n = 0;
    cin >> n;
    int f = 0;
    for(int i =0; i < n; i++){
        f = f ^ 0xFF;
        int tmp;
        cin >> tmp;

        if(f){
            table.push_back(tmp);
        }else{
            table.insert(table.begin(), tmp);
        }
    }
    if(n%2){
        reverse(table.begin(), table.end());
    }
    for(int i =0; i < n; i++){
        if(i != 0) cout << " ";
        cout << table[i];
    }
    cout << endl;
    return 0;
}   
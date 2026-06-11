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
    string a,b;
    cin >> a;
    cin >> b;
    for(int i =0; i < a.size() || i < b.size(); i++){
        if(i < a.size())
            cout << a[i];
        if(i < b.size())
            cout << b[i];
    }
    return 0;
    
}   
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    string o, e, ans = "";
    cin >> o >> e;
    int sum = o.size() + e.size();
    for(int i = 0; i < sum; ++i){
        if(i % 2 == 1) ans += e.at(i / 2);
        else if(i % 2 == 0) ans += o.at(i / 2);
    }
    cout << ans << endl;
    return 0;
}
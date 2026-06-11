#include <iostream>
using namespace std;
int main(void){
    string o,e;
    cin >> o;
    cin >> e;
    string ans = "";
    for(int i = 0;i < e.size();i++){
          ans += o[i];
          ans += e[i];
    }
    if(o.size() > e.size()) ans += o[o.size() - 1];
    cout << ans << endl;
}

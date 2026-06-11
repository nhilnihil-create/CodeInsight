#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string o, e, ans;
    cin >> o >> e;

    long long i = 0, j = 0;
    long long count = 0;
    while(i < o.size() || j < e.size()){
        if(count % 2 == 0){
            ans.push_back(o[i]);
            i++;
            count++;
        }
        else{
            ans.push_back(e[j]);
            j++;
            count++;
        }
    }
    cout << ans << endl;
    return 0;
}
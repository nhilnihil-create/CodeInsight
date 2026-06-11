#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(p[i] == i){
            if(i + 1 < n){
                int tmp = p[i];
                p[i] = p[i+1];
                p[i+1] = tmp;
                cnt++;
            }
            else{
                int tmp = p[i];
                p[i] = p[i-1];
                p[i-1] = tmp;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
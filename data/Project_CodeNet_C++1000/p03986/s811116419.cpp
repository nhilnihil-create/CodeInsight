#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string X;
    cin >> X;
    vector<long long> ct(2, 0);
    long long ans = X.size();
    for(int i = 0; i < X.size(); i++){
        if(X[i] == 'S') ct[0]++;
        else if(X[i] == 'T') ct[1]++;
        if(i >= 1){
            if(X[i] == 'S' && X[i - 1] == 'T'){
                ans -= min(ct[0] - 1, ct[1])*2;
                if(ct[0] - 1 > ct[1]) ct[0] = ct[0] - ct[1];
                else ct[0] = 1;
                ct[1] = 0;
            }
        }
    }
    if(X[X.size() - 1] == 'T'){
        ans -= min(ct[0], ct[1])*2;
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    for(int i = 0; i < k; i++) cin >> d[i];

    int ans = n;
    for(; ; ans++){
        string num = to_string(ans);
        bool isok = true;
        for(int i = 0; i < num.length(); i++){
            bool isok1 = true;
            for(int j = 0; j < d.size(); j++){
                if(num[i] == d[j]+'0'){
                    isok1 = false;
                }
            }
            if(!isok1){
                isok = false;
            }
        }
        if(isok) break;
    }
    cout << ans << endl;
    return 0;
}
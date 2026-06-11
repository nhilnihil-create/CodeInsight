#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<char>d(k);
    bool flg = 0;
    for(int i=0; i<k; i++) cin >> d[i];
    for(int i=n;;i++){
        string t = to_string(i);
        for(int j=0; j<t.size(); j++){
            for(int h=0; h<k; h++){
                if(t[j]==d[h]){
                    flg = 1;
                    break;
                }
            }
            if(flg) break;
        }
        if(!flg){
            cout << i << endl;
            return 0;
        }
        flg = 0;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<int> backet(9, 0);
    for(int i = 0; i < n; i++){
        if(c[i] / 400 < 8) backet[c[i]/400]++;
        else backet[8]++;
    }
    int minans = 0;
    int maxans = 0;
    for(int i = 0; i < 8; i++){
        if(backet[i] > 0) minans++;
    }

    if(backet[8] > 0 && minans == 0){
        minans = 1;
        maxans = backet[8];
    }else if(backet[8] > 0){
        maxans = minans + backet[8];
    }else{
        maxans = minans;
    }
    cout << minans << " " << maxans << endl;
    return 0;
}
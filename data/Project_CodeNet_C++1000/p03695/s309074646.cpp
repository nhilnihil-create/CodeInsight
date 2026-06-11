#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    vector<bool> a(8,0);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        if (b <= 399) a.at(0) = 1;
        else if(b <= 799) a.at(1) = 1;
        else if(b <= 1199) a.at(2) = 1;
        else if(b <= 1599) a.at(3) = 1;
        else if(b <= 1999) a.at(4) = 1;
        else if(b <= 2399) a.at(5) = 1;
        else if(b <= 2799) a.at(6) = 1;
        else if(b <= 3199) a.at(7) = 1;
        else if(b >= 3200) cnt++;
    }
    
    int min = 0;
    for (int i = 0; i < 8; i++) {
        if(a.at(i) == 1) min++;
    }
    
    int max = min;
    while (cnt > 0) {
        max++;
        cnt--;
    }
    if(min == 0) min = 1;
    cout << min <<  " " << max << endl;
}

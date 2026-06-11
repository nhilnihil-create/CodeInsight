#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c;

    cin >> a >> b >> c;

    int list[3] = {a, b, c};
    int cnt_5 = 0,cnt_7 = 0;

    for(int i = 0; i<3; i++){
        if(list[i] == 5)cnt_5++;
        if(list[i] == 7)cnt_7++;
    }

    if(cnt_5 == 2 && cnt_7 == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return  0;
}

#include <bits/stdc++.h>
using namespace std;


int main(void){
    long long int i,length_s,ans,cal,j;
    vector<long long int> num(20);
    ans = 0;

    string s;
    cin >> s;

    for(i=0; i<s.size(); i++){
        num.at(i) = s.at(i) - 48;
    }


    length_s = s.size();


    for(i=0; i < (1 << length_s - 1); i++){
        bitset<10> plus(i);
//        cout << plus << endl;
        cal = num.at(0);
        for(j = 0; j < length_s - 1; j++){
            if(plus[j] == 0){
                cal = cal * 10 + num.at(j+1);
//                cout << cal << endl;
            }else if(plus[j] == 1){
                ans += cal;
                cal = num.at(j+1);
//                cout << cal << endl;
            }
        }
        ans += cal;
//        cout << cal << endl;
    }

    cout << ans << endl;
    return 0;
}
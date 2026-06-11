#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i,capa_odd,capa_even;
    string odd,even;
    vector<string> pass(110);
    cin >> odd;
    cin >> even;

    capa_odd = odd.size();
    capa_even = even.size();

    for(i=0; i<capa_odd; i++){
        pass.at(2*i+1) = odd.at(i);
    }

    for(i=0; i<capa_even; i++){
        pass.at(2*i+2) = even.at(i);
    }

    for(i=0; i<pass.size(); i++){
        cout << pass.at(i);
    }
    cout << endl;
    return 0;
}
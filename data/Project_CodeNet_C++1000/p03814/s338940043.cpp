#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i,end,point_a,point_z;
    string s;
    cin >> s;

    end = s.size();

    for(i=0; i<end; i++){
        if(s.at(i) == 'A'){
            point_a = i;
            break;
        }
    }
    for(i=end-1; i>=point_a; i--){
        if(s.at(i) == 'Z'){
            point_z = i;
            break;
        }
    }

    cout << point_z - point_a  + 1 << endl;
    return 0;
}
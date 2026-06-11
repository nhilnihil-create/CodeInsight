#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(3);
    int s1,s2;
    int i,j,tmp;
    cin >> a.at(0) >> a.at(1) >> a.at(2);
    for(i=0;i<2;i++){
        for(j=1;i+j<3;j++){
        if(a.at(i)<a.at(i+j)){
            tmp = a.at(i+j);
            a.at(i+j) = a.at(i);
            a.at(i) = tmp;
        }
        }
    }
    s1 = a.at(2);
    s2 = a.at(1);

    cout << s1 + s2 << endl;

    return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string O,E;
    cin >>O>>E;
    if(O.size()==E.size()){
        for(int i=0;i<O.size();i++){
            cout << O.at(i)<<E.at(i);
        }
        cout <<endl;
    }
    else{
            for(int i=0;i<E.size();i++){
            cout << O.at(i)<<E.at(i);
        }
        cout <<O.at(E.size())<<endl;
    }
}
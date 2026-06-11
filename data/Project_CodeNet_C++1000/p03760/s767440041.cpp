#include<bits/stdc++.h>
using namespace std;

int main(){
    string o, e;
    cin >> o >> e;
    string pass="";
    for(int i=0; i<o.length(); i++){
        pass.push_back(o.at(i));
        if(o.length() == e.length()){
            pass.push_back(e.at(i));
        }else{
            if(i != o.length()-1){
                pass.push_back(e.at(i));
            }
        }
    }
    cout << pass << endl;
    return 0;
}
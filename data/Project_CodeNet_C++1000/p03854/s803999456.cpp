#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<string> div = {"maerd", "remaerd", "esare", "resare"};

    cin>> s;
    reverse(s.begin(), s.end());
   
    int i=0;
    while(1){
        bool flag = false;
        for(int j=0; j<4; j++){
            
            if(i+div[j].size()-1>s.size()-1){
                continue;
            }
            if(s.substr(i, div[j].size()) == div[j]){
                flag=true;
                i += div[j].size();
                break;
            }
        }

        if(!flag){
            cout<< "NO" << endl;
            return 0;
        }
        if(i>=s.size()){
            break;
        }
    }

    cout<< "YES" <<endl;
    return 0;
}
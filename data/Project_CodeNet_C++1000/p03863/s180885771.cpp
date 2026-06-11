#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int num_op=0;
    bool game_fin = false;
    while(!game_fin){
        bool can_op = false;
        int i_e;
        for(int i=1;i<s.size()-1;i++){
            if(s[i-1]!=s[i+1]){
                can_op=true;
                i_e = i;
                break;
            }
        }
        if(can_op) {
            s.erase(i_e,1);
            num_op++;
        }
        if(s.size()==2||!can_op) game_fin=true;
    }
    if(num_op%2==1){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}
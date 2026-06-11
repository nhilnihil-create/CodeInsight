#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<string>s(3);
    cin>>s[0];
    cin>>s[1];
    cin>>s[2];
    int turn=0;
    vector<int>index(3,0);
    int winner=-1;
    while(1){
        if(index[turn]==s[turn].size()){
            winner=turn;
            break;
        }
        int temp=turn;
        turn =s[turn][index[turn]]-'a';
        index[temp]++;
    }
    switch(winner){
        case 0:{cout<<"A";break;}
        case 1:{cout<<"B";break;}
        case 2:{cout<<"C";break;}
    }
}
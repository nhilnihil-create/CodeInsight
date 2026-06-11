#include <bits/stdc++.h>
using namespace std;
 

 
int main() {


    int h,w;
    cin>>h>>w;


    vector<vector<char>> C(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>C.at(i).at(j);
        }
    }


    //縦を2倍する
    vector<vector<char>> C2(2*h,vector<char>(w));
    for(int i=h-1;i>=0;i--){
        for(int j=0;j<w;j++){
            C2.at(i*2).at(j)=C.at(i).at(j);
        }
    }

    for(int i=0;i<2*h;i++){
        for(int j=0;j<w;j++){
            if(i%2==0)
                cout<<C2.at(i).at(j);
            else
                cout<<C2.at(i-1).at(j);
        }
            cout<<endl;
    }


 	return 0;
}

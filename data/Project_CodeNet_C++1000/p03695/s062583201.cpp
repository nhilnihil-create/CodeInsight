#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin>>N;
    vector<int>vec(N);
    vector<int>iro(8,0);
    int sanni=0;
    int count=0;
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
        if(vec.at(i)<=399){
            iro.at(0)++;
        }
        else if(400<=vec.at(i)&&vec.at(i)<=799){
            iro.at(1)++;
        }
        else if(800<=vec.at(i)&&vec.at(i)<=1199){
            iro.at(2)++;
        }
        else if(1200<=vec.at(i)&&vec.at(i)<=1599){
            iro.at(3)++;
        }
        else if(1600<=vec.at(i)&&vec.at(i)<=1999){
            iro.at(4)++;
        }
        else if(2000<=vec.at(i)&&vec.at(i)<=2399){
            iro.at(5)++;
        }
        else if(2400<=vec.at(i)&&vec.at(i)<=2799){
            iro.at(6)++;
        }
        else if(2800<=vec.at(i)&&vec.at(i)<=3199){
            iro.at(7)++;
        }
        else{
            sanni++;
        }
    }
     for(int i=0;i<8;i++){
         if(iro.at(i)>=1){
             count++;
         }
     }
            
    if(N==sanni){
        cout<<1<<' ';
    }
    else{
        cout<<count<<' ';
        }
    

    if(N==sanni){
            cout<<sanni<<endl;    
    }
    else{
            cout<<sanni+count<<endl;

    }
}
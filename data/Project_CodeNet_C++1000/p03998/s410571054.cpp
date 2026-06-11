#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string Sa,Sb,Sc;
    cin >> Sa >> Sb >> Sc;
    int a=0,b=0,c=0;
    char next='a';

    while(1){
        if(next=='a'){
            if(a==Sa.size()){
                cout << 'A' << endl;
                break;
            }
            else{
                next=Sa.at(a);
                a++;
            }
        }
        if(next=='b'){
            if(b==Sb.size()){
                cout << 'B' << endl;
                break;
            }
            else{
                next=Sb.at(b);
                b++;
            }
        }
        if(next=='c'){
            if(c==Sc.size()){
                cout << 'C' << endl;
                break;
            }
            else{
                next=Sc.at(c);
                c++;
            }
        }
    }
}
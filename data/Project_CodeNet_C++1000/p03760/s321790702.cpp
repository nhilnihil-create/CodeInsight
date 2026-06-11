#include <bits/stdc++.h>
using namespace std;
int main() {
 string O,E;
  cin>>O>>E;
 int o=O.size();
 int e=E.size();
 if(e>o){
   string k=O;
   O=E;
   E=k;    
 }
 int h=O.size();
 int g=E.size();
 for(int i=0; i<g; i++){
    cout<<O.at(i)<<E.at(i);
 }
 if(h>g){
    cout<<O.at(h-1);
 }
 cout<<""<<endl;
}
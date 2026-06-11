#include <bits/stdc++.h>
using namespace std;

int main(){
 int sx,sy,tx,ty;
 cin>>sx>>sy>>tx>>ty;
 int sax,say;
 sax=tx-sx;
 say=ty-sy;

 for(int i=0;i<say;i++){
        cout<<"U";
}
 for(int i=0;i<sax;i++){
        cout<<"R";
}

 for(int i=0;i<say;i++){
        cout<<"D";
}
 for(int i=0;i<sax;i++){
        cout<<"L";
}

 cout<<"L";
 for(int i=0;i<say+1;i++){
        cout<<"U";
}
 for(int i=0;i<sax+1;i++){
        cout<<"R";
}
cout<<"D";
cout<<"R";
for(int i=0;i<say+1;i++){
        cout<<"D";
}
for(int i=0;i<sax+1;i++){
        cout<<"L";
}
cout<<"U"<<endl;

return 0;
}

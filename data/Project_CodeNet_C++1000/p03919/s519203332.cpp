#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int h,w; cin>>h>>w;
    string s; int ansh; char answ;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>s;
            if(s=="snuke") {ansh=i+1; answ='A'+j; break;}
        }
    }
    cout<<answ<<ansh<<endl;
    return 0;
}

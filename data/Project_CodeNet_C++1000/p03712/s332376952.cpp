#include <iostream>
using namespace std;
int main(void){
    int h, w;
    cin>>h>>w;
    for(int z=1; z<=w+2; z++) cout<<"#";
    cout<<'\n';
    string c;
    for(int z=1; z<=h; z++) {
        cin>>c;
        cout<<"#"<<c<<"#"<<endl;
    }
    for(int z=1; z<=w+2; z++) cout<<"#";
    cout<<'\n';
    /*
    char a[100][100];
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }
    */
}

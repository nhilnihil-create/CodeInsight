#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int h ,w;
    cin >> h  >> w;
    string a[h];
    
    for (int g = 0;g < h;g++){
        cin >> a[g];
    }
   
    for(int i = 0; i <= h+1;i++){
        cout << "#";
        for(int j = 0;j <= w; j++){
        if(i == 0 && j != w || i == h+1 && j != w){
            cout <<"#";
        }    
        else if(1 <= i && i <= h && j != w){
            cout <<a[i-1][j];
        }
        else if(j == w){
            cout << "#" << endl;        
        }
        }
    }
    
}

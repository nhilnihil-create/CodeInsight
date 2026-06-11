#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int h,w;
    cin >> h >> w;
    
    vector<string> c(h);
    for(int i = 0;i < h;i++){
          cin >> c[i];
    }
    
    for(int i = 0;i < h;i++){
          for(int j = 0;j < 2;j++){
                cout << c[i] << endl;
          }
    }
}

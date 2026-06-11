#include<iostream>

using namespace std;

int main(){
    int n[3];
    int i, j;
    bool f = false;

    for (i=0; i<3; i++){
        cin >> n[i];
    }
    
    if (n[0]+ n[1] + n[2] == 17){
        for (i=0; i<3; i++){
            if (n[i] == 7){
                for (j=0; j<3; j++){
                    if (n[j] == 5){
                        f = true;
                        break;
                    }
                }
            }
        }
    }

    if (f == true){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
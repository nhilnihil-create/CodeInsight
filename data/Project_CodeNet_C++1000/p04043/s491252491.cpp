# include <iostream>
using namespace std;

int main() {
    int a[3];
    
    cin >> a[0] >> a[1] >> a[2];

    int count_5 = 0;
    int count_7 = 0;

    for(int i = 0; i < 3; i++){
        if(a[i] == 5){
            count_5++;
        }
        if(a[i] == 7){
            count_7++;
        }
    }

    if(count_5 == 2 && count_7 == 1){
        cout << "YES" << endl;
    } 
    else {
        cout << "NO" << endl;
    }
}
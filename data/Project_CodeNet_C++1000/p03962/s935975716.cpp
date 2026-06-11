# include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int count;

    cin >> a >> b >> c;
    
    if (a != b && b != c && a != c){
        count = 3;
    }
    else {
        if ((a == b && b != c) || (a == c && c != b) || (b == c && c != a)){
            count = 2;
        }
        else{
            count = 1;
        }
    }
    cout << count << endl;
}
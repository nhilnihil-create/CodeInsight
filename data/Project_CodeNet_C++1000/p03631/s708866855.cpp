#include <iostream>
#include <string>

using namespace std;

int main(){
    string n;
    cin >> n;
    string result = "No";
    if(n[0] == n[2]){
        result = "Yes";
    }
    cout << result << endl;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> divided = {64, 32, 16, 8, 4, 2, 1};
    for(size_t i = 0; i < divided.size(); i++){
        if(n >= divided[i]){
            cout << divided[i] << endl;
            return 0;
        }
    }
}
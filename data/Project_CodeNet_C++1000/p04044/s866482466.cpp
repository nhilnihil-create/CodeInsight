#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main (void){  
    int n, l;
    cin >> n >> l;
    vector <string> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    sort (array.begin(), array.end()); //ソート
    string result = "";
      for (int i = 0; i < n; i++) {
        result += array[i];
    }
    cout << result << endl;
    return 0;
}
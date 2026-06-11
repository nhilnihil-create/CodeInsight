#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(3, 0);
    for(int n=0; n<N; n++) {
        long long int a;
         cin >> a;
         if(a%4) {
            if(a%2) {
                vec[a%2]++;
            } else {
                vec[a%4]++;
            }
         } else {
            vec[a%4]++;
         }
    }
    
    if(vec[1]-vec[0]>1) {
        cout << "No" << endl;
    } else {
        if(vec[1]-vec[0]==1) {
            if(vec[2]) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        } else {
            cout << "Yes" << endl;
        }
    }
    

    return 0;
    
}
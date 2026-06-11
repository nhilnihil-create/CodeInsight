#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> a_vec;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a ;
        a_vec.push_back(a);
    }

    int cnt = 0;

    int idx = 0;

    int total = 0;

    //cout << "a_vec: " << a_vec.size() <<endl;

    do{
        cnt++;
        total++;

        int next = a_vec.at(idx);
        //cout << "next: " << next <<endl;

        if(next == 2){
            cout << cnt << endl;
            return 0;
        }
        idx = next -1;

    }while (total < N);

    cout << "-1" << endl;
 
    
}

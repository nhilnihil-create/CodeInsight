#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> a_vec;
    vector<int> b_vec;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a_vec.push_back(a);
        b_vec.push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        
        for (int j = 0; j < M; j++) {
            if(i == a_vec.at(j) || i == b_vec.at(j)){
                cnt++;
            }

        }
        cout << cnt << endl;

    }



}

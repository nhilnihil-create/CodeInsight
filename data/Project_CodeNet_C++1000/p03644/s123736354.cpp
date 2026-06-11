#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {

    int N;

    vector<int> n_vec;

    

    cin >> N ;

    for (int i = 1; i <= N; i++){

        n_vec.push_back(i);
    }

    
    int max_n = 0;
    int max_cnt = 0;;

    for (int i = 0; i < n_vec.size(); i++){

        int cnt = 0;
        int t = n_vec.at(i);
        do
        {
         t = t / 2;
         cnt++;
         if (t == 0){
             break;
         }   

        } while (true);

        if (max_cnt < cnt){
            max_cnt = cnt;
            max_n = n_vec.at(i);

        }

    }

    cout << max_n << endl;




}
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    int bre = 0;
    cin >> N;
    vector<int64_t> A(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    auto itr1 = A.begin();
    auto itr2 = itr1;
    itr2++;
    while(itr1 != A.end()){
        if(itr2 == A.end()){
            bre++;
            break;
        }

        if(*itr1 < *itr2){
            while(*itr1 <= *itr2 && itr2 != A.end()){
                itr1++;
                itr2++;
            }
            itr1++;
            itr2++;
            bre++;
        }

        else if(*itr1 > *itr2){
            while(*itr1 >= *itr2 && itr2 != A.end()){
                itr1++;
                itr2++;
            }
            itr1++;
            itr2++;
            bre++;
        }

        else if(*itr1 == *itr2){
            itr1++;
            itr2++;
        }
    }
    cout << bre << endl;
}
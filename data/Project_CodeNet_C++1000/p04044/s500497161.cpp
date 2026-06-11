#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int L;
    cin >> N;
    cin >> L;

    vector<string> A;

    string tmp;

    for(int i=0;i<N;i++){
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(),A.end());

    for(int i=0;i<A.size();i++)
        cout << A[i];

}
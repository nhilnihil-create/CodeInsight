#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> count;
    vector<int> unique_num;
    vector<int> bu(100001, 0);
    for(int n=0; n<N; n++) {
        cin >> A[n];
        
        if(bu[A[n]]==0) {
            unique_num.push_back(A[n]);
            count.push_back(0);
            bu[A[n]]++;
        } else {
            bu[A[n]]++;
            for(int ui=0; ui<unique_num.size(); ui++) {
                if(unique_num[ui]==A[n]) {
                    count[ui]++;
                }
            }
        }
    }
    
    int sum=0;
    for(int ui=0; ui<unique_num.size(); ui++) {
        sum += count[ui];
    }
    
    if(sum%2==0) {
        cout << unique_num.size() << endl;
    } else {
        cout << unique_num.size()-1 << endl;
    }

    return 0;
}
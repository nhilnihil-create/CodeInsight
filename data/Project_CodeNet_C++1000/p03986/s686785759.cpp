#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    string x;
    cin >> x;

    long long count_t = 0;
    long long count_s = 0;
    for(long long i = 0; i < x.size(); i++){
        if(x[i] == 'S'){
            count_s++;
        }
        else{
            if(count_s > 0){
                count_s--;
            }
            else{
                count_t++;
            }
        }
    }

    cout << count_t + count_s << endl;

    return 0;
}
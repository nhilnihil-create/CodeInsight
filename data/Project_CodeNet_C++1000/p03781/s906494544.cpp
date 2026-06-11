#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    int time_counter = 0;
    long long distance_accumulation=0;
    while (distance_accumulation < x){
        ++time_counter;
        distance_accumulation += time_counter;
    }
    cout << time_counter << endl;
    return 0;
}
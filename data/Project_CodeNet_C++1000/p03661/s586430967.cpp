#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cards(n);
    for (int i=0;i<n;i++){
        cin >> cards[i];
    }
    vector<long long> left_scan_acc(n);
    vector<long long> right_scan_acc(n);
    for (int i=0;i<n;i++){
        if (i == 0){
            left_scan_acc[i] = cards[i];
        } else {
            left_scan_acc[i] = left_scan_acc[i-1] + cards[i];
        }
    }

    for (int i=0;i<n;i++){
        if (i == 0){
            right_scan_acc[n-i-1] = cards[n-i-1];
        } else {
            right_scan_acc[n-i-1] = right_scan_acc[n-i] + cards[n-i-1];
        }
    }

    long long minimum_value;
    for (int i=0;i<n-1;i++){
        if (i == 0){
            minimum_value = abs(left_scan_acc[i] - right_scan_acc[i+1]);
        } else {
            minimum_value = min(minimum_value, abs(left_scan_acc[i] - right_scan_acc[i+1]));
        }
    }
    cout << minimum_value << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int> a(N);
    int sum = 0;
    for (int i=0; i<N;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    int cost = 100000000;
    for (int q= -100; q<101; q++){
        int temp = 0;
        for (int i= 0; i<a.size(); i++) {
            temp += (a[i]-q)*(a[i]-q);

        }
        cost = min(cost, temp);
    }
    cout << cost << endl;
    return 0;

}

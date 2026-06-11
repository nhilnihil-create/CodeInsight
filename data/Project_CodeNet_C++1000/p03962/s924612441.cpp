#include <iostream>
#include <string.h>

using namespace std;

int main () {
    int a, b, c;
    int array[100];
    memset(array, 0, 100 * sizeof(int));
    cin >> a >> b >> c;

    array[a-1]++;
    array[b-1]++;
    array[c-1]++;
    int count = 0;
    for(int i = 0; i<100; i++) {
        if (array[i] > 0) count++;
    }
    cout << count << endl;
}

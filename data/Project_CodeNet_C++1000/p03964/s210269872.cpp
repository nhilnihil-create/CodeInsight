#include <iostream>
#include<map>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include<math.h>
#define int long long
const int maxvalue = 2 * 1e5;


using namespace std;


void solver() {

    int n;
    cin >> n;
//    int *arr=new int[2*n];
//    for(int i=0;i<2*n;i++)
//    {
//        cin>>arr[i];
//    }
    int c ;
    int d ;
    cin>>c>>d;
    while (n-1 > 0) {


        int a, b;
        cin >> a >> b;
        int my1 = c / a;
        if(c%a!=0)
        {
            my1++;
        }
        int my2 = d / b;
        if(d%b!=0)
        {
            my2++;
        }
        c = a * max(my1, my2);
        d = b * max(my1, my2);
        n--;

    }
    cout << c + d;


}

int32_t main() {
    int n=1;
    //cin >> n;
    while (n--) {
        solver();
    }
}
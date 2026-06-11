#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int AB,BC,AC;
    AB=a+b;BC=b+c;AC=a+c;
    cout<<min(AB,min(BC,AC))<<endl;
    return 0; 
}
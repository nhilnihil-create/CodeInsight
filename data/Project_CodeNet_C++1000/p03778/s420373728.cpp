#include <bits/stdc++.h>
using namespace std;
int main() {
    int W,a,b;
    cin>>W>>a>>b;
    if (W+a<b){
        cout<<b-(W+a);
    }
    else if (W+b<a){
        cout<<a-(W+b);
    }
    else{
        cout<<"0";
    }
	return 0;
}

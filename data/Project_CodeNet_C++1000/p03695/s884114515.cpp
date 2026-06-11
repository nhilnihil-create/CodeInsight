#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int free=0;
    set<string> colors;
    for (int i=0; i<n; i++){
        int rate; cin >> rate;
        if(rate<400) colors.insert("grey");
        else if(rate<800) colors.insert("brown");
        else if(rate<1200) colors.insert("green");
        else if(rate<1600) colors.insert("sky");
        else if(rate<2000) colors.insert("blue");
        else if(rate<2400) colors.insert("yellow");
        else if(rate<2800) colors.insert("orange");
        else if(rate<3200) colors.insert("red");
        else{
            free += 1;
        }
    }
    int g = colors.size();
    int minimum, maximum;
    if(g==0){
        minimum = 1;
        maximum = free;
    }
    else{
        minimum = g;
        maximum = g+free;
    }
    cout << minimum << ' ' << maximum << endl;
}
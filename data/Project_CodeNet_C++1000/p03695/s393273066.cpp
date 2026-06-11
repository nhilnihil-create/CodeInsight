#include <bits/stdc++.h>
using namespace std;
 
int getMin(int min, int &wild){
    if (min == 0){
      	wild--;
        return 1;
    }else{
        return min;
    }
}
 
int getMax(int min, int wild){
    int max = 0;
    
    // if (min + wild >= 8){
    //     max = 8;
    // }else{
    //     max = min + wild;
    // }
    max = min + wild;
 
    return max;
}
 
int main(){
 
    int n;
    cin >> n;
 
    vector<bool> colors(8, false);
    int wild = 0;
 
    for (int i = 0; i<n; i++){
        int a;
        cin >> a;
        if (a >= 3200){
            wild++;
            continue;
        }
        
        colors.at(a/400) = true;
    }
 
    int min = 0;
    int max = 0;
 
    for (bool i: colors){
        if (i){
            min++;
        }
    }
 
    min = getMin(min, wild);
    max = getMax(min, wild);
    
    cout << min << " " << max << endl;
 
    return 0;    
}
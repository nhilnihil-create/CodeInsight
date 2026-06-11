//
//  main.cpp
//  comp
//
//  Created by Brenda Aurelie on 6/14/20.
//  Copyright © 2020 Brenda Aurelie. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int n,temp;
    cin >> n;
     int arr[2*n];
    for(int i=0;i<2*n;i++){
        cin >> arr[i];
    }
    
    
    for (int i=0;i<2*n;i++){
        for(int j=i+1;j<2*n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    
    int sum=0;
    
    for(int i=0;i<n;i++){

        sum += arr[i*2];
    
    }
    
    
    cout << sum << endl;
    
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
   int main()
   {
       int N;
       cin >> N;
       vector<int> vec(N);
       for (int i=0; i<N; i++) {
           cin >> vec.at(i);
       }
       int is_2 = false;
       int next = 1;
       int count = 1;
       for (int i=0; i<N; i++) {
           if (vec.at(next-1)==2) {
               is_2 = true;
               break;
           } else {
               count++;
               next = vec.at(next-1);
           }
       }
       cout << ((is_2) ? count : -1)<< endl;
    }
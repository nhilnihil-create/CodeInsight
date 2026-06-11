#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include <stdlib.h>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Queue {
   public:
   	int *array;
    int front, rear;
    int capacity;

	Queue(int size) {
     array = new int[size];
     front = rear = 0;
     capacity = size;
     int men = sizeof(array)/sizeof(array[0]);
     cout << men << "\n";
	} 
    void enqueue(int data);
    int peek();
    void dequeue();
    bool isEmpty();
    bool isFull();
    void print();
};

void Queue::enqueue(int data) {
	if(isFull()) {
       cout << "Queue is full, you cannot push an element!" << "\n";
	} else {

    array[rear] = data;
    rear++;

}
}

void Queue::dequeue() {

	if(isEmpty()) {
		cout << "there is no element to remove " << "\n";
	}
	else {
	    cout << "removing " << array[front] <<  "\n";
	    front = front + 1;
	}
}

bool Queue::isFull() {
	if(rear == capacity) {
		return true;

	}
	return false;
}
bool Queue::isEmpty() {
   if(front == 0 || front == rear) {
   	 return true;
   }
   return false;
}

void Queue::print()  {
	if(isEmpty()) {
		cout <<  " there is no element in the Queue " << "\n"; 
	} else {
	for(int i = front; i < rear; i++) {
		cout << array[i] << " ";
	}
	cout << "\n"; 
}
}

int main () {
 /*   Queue queue(10);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);

    queue.print();
    queue.print();
 */   
  /*
     vector<int> nums = {1, 1, 2, 2, 3, 4, 5, 5, 6};

     vector<pair<bool, int>> visited(nums.size());
     for(int i = 0; i < nums.size(); i++){
     	if(visited) {
     		visited = true;	
     	}
     }*/

    int h, w;
     cin >> h >> w;
     vector<vector<string>>  snuke(h, vector<string> (w));

     for(int i = 0; i < h; i++) {
     	for(int j = 0;  j < w; j++) {
     		cin >> snuke[i][j];
     	}
     }
   
   char alphaSet[26] = {'A', 'B', 'C', 'D', 'E', 'F','G', 'H','I', 'J', 'K', 'L','M', 'N',
         'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};   
     for(int i = 0; i < h; i++) {
     	for(int j = 0;  j < w; j++) {
         if(snuke[i][j] == "snuke") {
         	cout << alphaSet[j]  << i + 1 << "\n";
         	return 0;
         }
     	}
     }


	 return 0;
}

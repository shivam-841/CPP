/* priority queue
A priority queue is a type of data structure is similar to queue, but elements are ordered based on a priority.
	-> In this the element with highest priority get dequeued first.
	-> It can  be thought of a max-heap or a min-heap.
	-> It is under the header file #include<queue>

** Implmentation**
	-> A priority queue is implmented using a heap(typically a binary heap).
	Note: 
	  -> Heap is a complete binary tree with heap property either a max heap or min heap.
  	-> It is built on top of a container usually a vector, but can also be a deque.
*/

/*Declaration*/
	#include<queue> //header for priority queue
	int main(){
		std::priority_queue<int> pq;
	}

/*Operation on elements*/
	pq.push(10); //Insert 10 into the priority queue
	pq.top(); //It will return element with highest priority (largest element)
    pq.pop(); //It will remove the element with highest priority

/*Min-Heap (customizing priority queue)*/
    #include <functional> // for std::greater
    int main(){
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq; //customized declaration for min-heap
    }

#include <iostream>

using namespace std;

class queue{
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;
    public:
        queue(int s);
        bool isempty();
        bool isfull();
        void enqueue(int a);
        void dequeue();
        int size();
};

queue::queue(int s){
    arr = new int[s];
    capacity = s;
    count = 0;
    front = 0;
    rear = -1;
    
}

void queue::enqueue(int a){
    if(isfull()){
        cout<<"queue is full "<<endl;
        exit(EXIT_FAILURE);
    }
    rear = (rear+1)%capacity;
    arr[rear] = a;
    count++;
    
    
}

void queue::dequeue(){
    if(isempty()){
        cout<<"queue is empty "<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"removed this element "<<arr[front]<<endl;
    count--;
    front = (front+1)%capacity;

}

bool queue::isempty(){
    return(size()==0);
}

bool queue::isfull(){
    return(size() == capacity);
    
}

int queue::size(){
    return count;    
}

int main() {
    queue q(15);
	q.enqueue(12);
	q.enqueue(2);
	q.enqueue(3);
	q.dequeue();
	q.dequeue();
	
}

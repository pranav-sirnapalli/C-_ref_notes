#include<iostream>

using namespace std;

class Queue{
	private:
		int font;
		int rear;
		int arr[5];
		
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			for(int i=0; i<5; i++)
			{
				arr[i] = 0;
			}	
		}
		
		bool isEmpty()
		{
			if(front == -1 && rear == -1)
				return true;
			else
				return false;
		}
		
		bool isFull()
		{
			if(rear == 4)
				return true;
			else
				return false;
		}
		
		void enqueue(int val)
		{
			if(isFull())
			{
				cout << "Queue is FULL" << endl;
				return;
			}
			
			else if(isEmpty())
			{
				rear = 0;
				front = 0;
				arr[rear] = val;
			}
			
			else
			{
				rear++;
				arr[rear] = val;
			}
		}
		
		int dequeue()
		{
			int x;
			if(isEmpty())
			{
				cout << "Queue is EMPTY" << endl;
				return 0;
			}
			else if(front == rear)
			{
				x = arr[front]; 
				arr[front] = 0;
				rear = -1;
				front = -1;
				return x;
			}
			
			else
			{
				x = arr[front];
				arr[front] = 0;
				front++;
				return x;
			}
		}
		
		int count()
		{
			return (rear-front+1);
		}
		
		void display()
		{
			cout << "All the values in the Queue are - " << endl;
			for(int i=0; i<5; i++)
			{
				cout << arr[i] << " ";
			}
		}
};

int main()
{
	Queue q1;
	int option, value;
	
	do
	{
		cout << "\n\nWhat do you want to perform? Select option number. Enter o to exit" << endl;
		cout << "1. Enqueue()" << endl;
		cout << "2. Dequeue()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. count()" << endl;
		cout << "6. display()" << endl;
		cout << "7. Clear screen" << endl;
		
		cin >> option;
		
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout << "Enqueu Operation\n Enter the item to enqueue in the queue" << endl;
				cin >> value;
				q1.enqueue(value);
				break;

			case 2: 
				cout << "Dequeue opeation\n Dequeud value :" << q1.dequeue() << endl;
				break;
				
			case 3:
				if(q1.isEmpty())
					cout << "Queue is Empty" << endl;
				else
					cout << "Queue is not Empty" << endl;
				break;
			
			case 4:
				if(q1.isFull())
					cout << "Queue is Full" << endl;
				else
					cout << "Queue is not Full" << endl;
				break;
				
			case 5:
				cout << "Count operation\n Count of items in Queue: " << q1.count() << endl;
				break;
				
			case 6:
				cout << "Display function called - " << endl;
				q1.display()
				break;
				
			case 7:
				system("cls");
				break;
				
			default:
				cout << "Enter proper option number" << endl;
				break;
		}
	}while(option != 0);
}

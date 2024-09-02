#include<iostream>

using namespace std;

class Node{
	public:
		int key;
		int data;
		Node *next;
		
		Node()
		{
			key = 0;
			data = 0;
			next = NULL;
		}
		
		Node(int k, int d)
		{
			key = k;
			data = d;
		}
};

class CircularLinkedList{
	public:
		Node* head;
		
		CircularLinkedList()
		{
			head = NULL;
		}
		
		Node* nodeExists(int k)
		{
			Node *temp = NULL;
			Node *ptr = head;
			
			if(ptr == NULL)
			{
				return temp;
			}
			
			else
			{
				do
				{
					if(ptr->key == k)
					{
						temp = ptr;
					}
					ptr = ptr->next;
				}while(ptr != head);
				return temp;
			}		
		}
		
		void appendNode(Node *new_node)
		{
			if(nodeExists(new_node->key) != NULL)
			{
				cout << "Node already exists with key value: " << 
				new_node->key << ".Append another node with different key value"
				<< endl;
			}
			
			else
			{
				if(head == NULL)
				{
					head = new_node;
					new_node->next = head;
					cout << "Node appended at first head position" << endl;
				}
				
				else
				{
					Node* ptr = head;
					while(ptr->next != head)
					{
						ptr = ptr->next;
					}
					ptr->next = new_node;
					new_node->next = head;
					cout << "Node Appended" << endl;
				}
			}
		}
		
		void prependNode(Node* new_node)
		{
			if(nodeExists(new_node->key) != NULL)
			{
				cout << "Node already exists withkey value: "
				<< new_node->key
				<< ".Append another node with different value."
				<< endl;
			}
			
			else
			{
				Node *ptr = head;
				while(ptr->next != head)
				{
					ptr = ptr->next;
				}
				ptr->next = new_node;
				
				new_node->next = head;
				head = new_node;
				cout << "Node Prepended" << endl;
			}
		}
		
		void insertNodeAfter(int k, Node *new_node)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "No such node exists";
			}
			
			else
			{
				if(nodeExists(new_node->key) != NULL)
				{
					cout << "Node already exists with key value:"
					<< new_node->key
					<< ".Append another node with different key value."
					<< endl;
				}
				else
				{
					if(ptr->next == head)
					{
						new_node->next = head;
						ptr->next = new_node;
						cout << "Node Inserted at the End." << endl;
					}
					
					else
					{
						new_node->next = ptr->next;
						ptr->next = new_node;
						cout << "Node Inserted in between" <<endl;
					}
				}
			}
		}
		
		void deleteNodeByKey(int k)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				
			}
		}
		
		
		
};

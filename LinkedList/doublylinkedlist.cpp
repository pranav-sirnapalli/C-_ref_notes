#include<iostream>

using namespace std;

class Node
{
	public:
		int key;
		int data;
		Node *next;
		Node *previous;
	
	Node()
	{
		key=0;
		data=0;
		next=NULL;
		previous=NULL;
	}	
	
	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class DoublyLinkedList{
	public:
		Node *head;
	
		DoublyLinkedList()
		{
			head = NULL;
		}
		
		DoublyLinkedList(Node *n)
		{
			head = n;
		}
		
		Node* checkIfnodeExists(int k)
		{
			Node *temp = NULL;
			Node *ptr = head;
			
			while(ptr != NULL)
			{
				if(ptr->key == k)
				{
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		void appendNode(Node *n)
		{
			if(checkIfNodeExists(n->key) != NULL)
			{
				cout << "Node Already exists with key value: " << n->key << ".Append another node with different key value." << endl;
			}
			
			else
			{
				if(head == NULL)
				{
					head = n;
					cout << "Node appended" << endl;
				}
				
				else
				{
					Node *ptr = head;
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
					n->previous = ptr;
					cout << "Node Appended" << endl;
				}
			}
		}
		
		void prependNode(Node *n)
		{
			if(ndoeExists(n->key) != NULL)
			{
				cout << "Node already exists with key value: " << n->key << ".Append another node with different key value" << endl;
			}
		
			else
			{
				if(head == NULL)
				{
					head = n;
					cout << "Node appended" << endl;
				}
				
				else
				{
					head->previous = n;
					n->next = head
					head = n;
					cout << "Node prepended" << endl;
				}
			}	
		}
		
		void insertNodeAfter(int k, Node *n)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "No node exists with key value: " << k << endl;
			}
			
			else
			{
				if(nodeExists(n->key) != NULL)
				{
					cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
				}
				
				else
				{
					cout << "Inserting" << endl;
					
					Node *nextNode = ptr->next;
					
					if(nextNode == NULL)
					{
						ptr->next = n;
						n->previous = ptr;
						cout << "Node inserted at the END" << endl;
					}
					
					else
					{
						n->next = nextNode;
						nextNode->previous = n;
						n->previous = ptr;
						ptr->next = n;
						
						cout << "Node inserted in between" << endl;
					}
				}
			}
		}
		
		void deleteNodeByKey(int k)
		{
			Node *ptr = nodeExists(k);
			if(ptr == NULL)
			{
				cout << "No node exists with key value: " << k << endl;
			}
			
			else
			{
				if(head->key == k)
				{
					head = head->next;
					cout << "Node unlinked with keys value: " << k << endl;
				}
				
				else
				{
					Node *nextNode = ptr->next;
					Node *prevNode = ptr->previous;
					if(nextNode == NULL)
					{
						prevNode->next = NULL;
						cout << "Node Deleted at the END" << endl;
					}
					
					else
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout << "Node Deleted in between" << endl;
					}
				}
			}	
		}
		
		void updateNodeByKey(int k, int d)
		{
			Node I*ptr = nodeExists(k);
			
			if(ptr != NULL)
			{
				ptr->data = d;
				cout << "Node Data Updated Successfully" << endl;
			}
			
			else
			{
				cout << "Node Doesen't exist with key value" << endl;
			}
		}
		
		void printList()
		{
			if(head == NULL)
			{
				cout << "No nodes in Doubly linked list";
			}
			
			else
			{
				cout << endl << "Doubly Linked List Values";
				
				Node *temp = head;
				while(temp != NULL)
				{
					cout << "(" << temp->key << "," << temp->data << ") <--> ";
					temp = temp->next; 
				}
			}
		}
};

void main()
{
	DoublyLinkedList obj;
	int option;
	int key1, k1, data1;
	
	do
	{
		cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit" << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl;
		
		cin >> option;
		
		Node* n1 = new Node();
		
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout << "Append node operation\n Enter key and data of the Node to be Appended" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.appendNode(n1);
				break;
				
			case 2:
				cout << "Insert node after Operation \nEnter key of existing node after which you want to insert this new node: ";
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.prependNode(n1);
				break;
			
			case 3:
				cout << "Insert node after operatuion\n Enter key of existing node after which you want to insert this new node: ";
				cin >> k1;
				cout << "Enter key & data of the new node first: " << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.insertNodeAfter(k1, n1);
				break;
			
			case 4:
				cout << "Delete node by key operation- \nEnterkey of the node to be deleted: " << endl;
				cin >> k1;
				obj.deleteNodeByKey(k1);
				break;
			
			case 5:
				cout << "Update Node by key operation -\nEnter key & new data to be updated" << endl;
				cin >> key1;
				cin >> data1;
				obj.updateNodeByKey(key1, data1);

			case 6:
				obj.printList();
				break;
			
			case 7:
				system("cls");
				break;
			default:
				cout << "Enter proper option number" << endl;			
		}		
	}while(option != 0);
	
}

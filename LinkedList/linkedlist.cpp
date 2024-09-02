
#include<iostream>

using namespace std;

class Node
{
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

class SinglyLinkedList
{
	public:
		Node* head;
	
	SinglyLinkedList()
	{
		head = NULL;
	}
	
	SinglyLinkedList(Node *n)
	{
		head = n;
	}
	
	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		
		Node* ptr = head;
		while(ptr != NULL)
		{
			if(ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next
		}
		return tmp;
	}
	
	void appendNode(Node *n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
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
				cout << "Node Appended" << endl;
			}
		}
	}
	
	void prependNode(Node *n)
	{
		if(nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value:" << n->key <<".append another node with different key value" << endl;
		}
		
		else
		{
			n->next = head;
			head = n;
			cout << "Node prepended" << endl;
		}
	}
	
	void insertNodeAfter(int k, Node *n)
	{
		Node *ptr = nodeExists(k)
		if(ptr == NULL)
		{
			cout << "Node prepended";
		}
		else
		{
			if(nodeExists(n->key) != NULL)
			{
				cout << "Node already exists with key value:" << n->key << ".Append another node with different key value" << endl;
			}
			else
			{
			 	n->next = ptr->next;
			 	ptr->next = n;
			 	cout << "Node Inserted" << endl;
			}
		}
	}
	
	void deleteNodeByKey(int k)
	{
		if(head == NULL)
		{
			cout << "Singly Linked List already Empty. Cant delete" << endl;
		}
		
		else if(head != NULL)
		{
			if(head->key == k)
			{
				head = head->next
				cout << "Node Unlinked with key value:" << k << endl;
			}
			
			else
			{
				Node *tmp = NULL;
				Node *prevptr = head;
				Node *currentptr = head->next;
				
				while(currentptr != NULL)
				{
					if(currentptr->key == k)
					{
						tmp = currentptr;
						currentptr = NULL;
					}
					
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				
				if(tmp != NULL)
				{
					prevptr->next = tmp->next;
					cout << "Node unlinked with keys value: " << k << endl;
				}
				
				else
				{
					cout <<"Node Doesen't exit with key value" << k << endl;
				}
			}
		}
	}
	
	void updateNodeByKey(int k, int d)
	{
		Node *ptr = nodeExists(k);
		if(ptr != NULL)
		{
			ptr->data = d;
			cout << "Node data updated Successfully" << endl;
		}
		
		else
		{
			cout << "Node Doesen't exist with key value: " << k << endl;
		}
	}
	
	void printList()
	{
		if(head == NULL)
		{
			cout << "No Nodes in singly linked list";
		}
		
		else
		{
			cout << endl << "Singly Linked List values";
			Node* temp = head;
			
			while(temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ") -->";
				temp = temp->next;
			}
		}
	}
};

void main()
{
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	
	do
	{
		cout << "\nWhat operation do you want to perform? select option number. Enter 0 to exit. << endl";
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
				s.appendNode(n1);
				break;
				
			case 2:
				cout << "Insert node after Operation \nEnter key of existing node after which you want to insert this new node: ";
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.prependNode(n1);
				break;
			
			case 3:
				cout << "Insert node after operatuion\n Enter key of existing node after which you want to insert this new node: ";
				cin >> k1;
				cout << "Enter key & data of the new node first: " << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				s.insertNodeAfter(k1, n1);
				break;
			
			case 4:
				cout << "Delete node by key operation- \nEnterkey of the node to be deleted: " << endl;
				cin >> k1;
				s.deleteNodeByKey(k1);
				break;
			
			case 5:
				cout << "Update Node by key operation -\nEnter key & new data to be updated" << endl;
				cin >> key1;
				cin >> data1;
				s.updateNodeByKey(key1, data1);

			case 6:
				s.printList();
				break;
			
			case 7:
				system("cls");
				break;
			default:
				cout << "Enter proper option number" << endl;			
		}
				
	}while(option != 0);
	
}

//#include<iostream>
//using namespace std;
//template<typename t>
//struct Node {
//	t data;
//	Node<t>* previous;
//	Node<t>* next;
//};
//template<typename t>
//class doublylinkedlist {
//private:
//	Node<t>* head;
//	Node<t>* tail;
//public:
//	doublylinkedlist() {
//		head = NULL;
//		tail = NULL;
//	}
//	void insert(t element)
//	{
//		Node<t>* newnode = new Node<t>;
//		if (head == NULL) {
//			head = newnode;
//			newnode->data = element;
//			newnode->next = NULL;
//			newnode->previous = NULL;
//			tail = newnode;
//		}
//		else {
//			newnode->data = element;
//			newnode->previous = tail;
//			newnode->next = NULL;
//			tail->next = newnode;
//			tail = newnode;
//		}
//	}
//	void print()
//	{
//		Node<t>* temp = new Node<t>;
//		temp = head;
//		cout << "Doubly linked list is: ";
//		while (temp->next != NULL)
//		{
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//		cout << temp->data;
//	}
//	void Swap(t x, t y)
//	{
//		Node<t>* temp1 = new Node<t>;
//		Node<t>* temp2 = new Node<t>;
//		Node<t>* temp3 = new Node<t>;
//		Node<t>* count;
//		bool flagx = false, flagy = false;
//		count = head;
//		while (count->next != NULL)
//		{
//			if (count->data == x) {
//				temp1->data = x;
//				temp1->next = count->next;
//				temp1->previous = count->previous;
//				flagx = true;
//			}
//			if (count->data == y) {
//				temp2->data = y;
//				temp2->next = count->next;
//				temp2->previous = count->previous;
//				flagy = true;
//			}
//			count = count->next;
//		}
//
//		if (flagx == true && flagy == true)
//		{
//			if (temp1->previous == NULL)
//			{
//				if (temp1->next->data == y)
//				{
//					temp2->next->previous = temp1;
//					temp1->next = temp2->next;
//					temp1->previous = temp2;
//					temp2->next = temp1;
//					temp2->previous = NULL;
//					head = temp2;
//				}
//				else if (temp1->next->data != y)
//				{
//
//					temp3->next = temp1->next;
//					temp3->previous = temp1->previous;
//
//					temp1->next = temp2->next;
//					temp1->previous = temp2->previous;
//
//					temp2->next = temp3->next;
//					temp2->previous = temp3->previous;
//
//					temp2->next->previous = temp2;
//
//					temp1->previous->next = temp1;
//					temp1->next->previous = temp1;
//					head = temp2;
//
//				}
//			}
//			else if (temp1->previous != NULL)
//			{
//				if (temp1->next->data != y)
//				{
//					temp3->next = temp1->next;
//					temp3->previous = temp1->previous;
//
//					temp1->next = temp2->next;
//					temp1->previous = temp2->previous;
//
//					temp2->next = temp3->next;
//					temp2->previous = temp3->previous;
//
//					temp2->previous->next = temp2;
//					temp2->next->previous = temp2;
//
//					temp1->previous->next = temp1;
//					temp1->next->previous = temp1;
//
//				}
//				else if (temp1->next->data == y)
//				{
//					temp2->previous = temp1->previous;
//					temp1->previous->next = temp2;
//					temp1->next = temp2->next;
//					temp1->previous = temp2;
//					temp2->next = temp1;
//					temp1->next->previous = temp1;
//				}
//				else if (temp1->previous->data == y)
//				{
//					temp1->previous = temp2->previous;
//					temp2->previous->next = temp1;
//					temp2->next = temp1->next;
//					temp2->previous = temp1;
//					temp1->next = temp2;
//					temp2->next->previous = temp2;
//				}
//			}
//		}
//		else
//		{
//			cout << "\nElement dont exist\n";
//			exit(0);
//		}
//	}
//	~doublylinkedlist() {
//		Node<t>* temp;
//		temp = head->next;
//		while (temp != NULL) {
//			delete head;
//			head = temp;
//			temp = temp->next;
//		}
//	}
//};
//int main()
//{
//	doublylinkedlist<int> obj1;
//	obj1.insert(10);
//	obj1.insert(15);
//	obj1.insert(12);
//	obj1.insert(13);
//	obj1.insert(20);
//	obj1.insert(14);
//
//	obj1.print();
//
//	obj1.Swap(0, 13);
//	cout << "\n After swapping: ";
//	obj1.print();
//
//	return 0;
//}

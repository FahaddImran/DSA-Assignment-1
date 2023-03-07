//#include<iostream>
//using namespace std;
//template<typename t>
//struct Node {
//	t data;
//	Node<t>* next;
//	Node<t>* previous;
//};
//template<typename t>
//class circularlinklist {
//private:
//	Node<t>* head;
//	Node<t>* tail;
//public:
//	circularlinklist()
//	{
//		head = NULL;
//		tail = NULL;
//	}
//	
//	void print() {
//		Node<t>* temp1, *temp2;
//		temp1 = tail;
//		temp2 = head;
//		cout << "Circular linked list is: ";
//		while (temp2 != temp1) {
//			cout << temp2->data << " ";
//			temp2 = temp2->next;
//		}
//		cout << temp2->data << " ";
//	}
//	void createLL(int arr[], int size) {
//		for (int i = 0; i < size; i++) 
//		{
//			Node<t>* newnode = new Node<t>;
//			newnode->data = arr[i];
//			if (head == NULL && tail == NULL) {
//				head = newnode;
//				tail = newnode;
//				head->next = head;
//				head->previous = head;
//			}
//			else {
//				newnode->previous = tail;
//				tail->next = newnode;
//				tail = newnode;
//				newnode->next = head;
//				head->previous = newnode;
//			}
//		}
//	}
//};
//
//int main() {
//	
//
//	circularlinklist<int> l1;
//	// Array to be converted
//	int arr[] = { 1,2,3,4,5 };
//	int s = sizeof(arr) / sizeof(arr[0]);
//	l1.createLL(arr, s);
//	// Display the list
//	l1.print();
//	return 0;
//
//}
#include<iostream>
using namespace std;
template<typename t>
struct Node {
	t data;
	struct Node* next;
};
template<typename t>
class linkedlist {
private:
	Node<t>* head;
	Node<t>* tail;
public:
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	void add(t element)
	{
		Node<t>* newnode = new Node<t>;
		if (head == NULL) {
			head = newnode;
			newnode->next = NULL;
			newnode->data = element;
			tail = newnode;
		}
		else {
			newnode->data = element;
			newnode->next = NULL;

			tail->next = newnode;
			tail = newnode;
		}

	}
	void insert(t d)
	{
		Node<t>* newnode = new Node<t>;
		Node<t>* temp = new Node<t>;
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->next->next == NULL)
			{
				newnode->data = d;
				newnode->next = temp->next;
				temp->next = newnode;
				break;
			}
			else
				temp = temp->next;
		}
	}
	void Delete()
	{
		if (head == NULL)
		{
			cout << "Link list is empty";
		}
		else
		{
			Node<t>* temp = new Node<t>;
			temp = head;
			temp = temp->next;
			head->next = head->next->next;
			delete temp;
		}
	}
	linkedlist& merge(linkedlist& obj1)
	{
		linkedlist obj3;

		Node<t>* temp1;
		Node<t>* temp2;
		temp1 = obj1.tail;
		temp2 = this->head;

		temp1->next = temp2;

		obj3.head = obj1.head;
		obj3.tail = this->tail;

		return obj3;
	}
	void compress()
	{
		Node<t>* temp1;
		Node<t>* temp2;
		temp1 = head;
		temp2 = head->next;
		while (temp1->next != NULL)
		{
			if (temp1->data == temp2->data)
			{
				temp1->next = temp1->next->next;
				temp2 = temp1;
			}
			if (temp2->next == NULL) {
				temp1 = temp1->next;
				temp2 = temp1;
			}
			temp2 = temp2->next;
		}
	}
	void print()
	{
		Node<t>* temp;
		temp = head;
		while (temp->next != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;

	}
};

int main()
{
	linkedlist<int> l1;
	l1.add(10);
	l1.add(40);
	l1.add(30);
	l1.add(30);
	l1.add(50);
	cout << "LINKED LIST: ";
	l1.print();
	cout << endl;

	l1.compress();
	cout << "After compressing: ";
	l1.print();
	cout << endl;

	l1.insert(5);
	cout << "After insertion: ";
	l1.print();
	cout << endl;

	l1.Delete();
	cout << "After deletion: ";
	l1.print();
	cout << endl;

	linkedlist<int> l2;
	l2.add(50);
	l2.add(50);
	l2.add(70);
	l2.add(50);
	l2.add(30);
	cout << "LINKED LIST 2: ";
	l2.print();
	cout << endl;

	l1.merge(l2);
	cout << "After merging: ";
	l2.print();
	cout << endl;

	return 0;
}
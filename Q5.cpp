//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//class SparseMatrix {
//	struct Node {
//		int value;
//		int colindex;
//		Node* nextInRow;
//	};
//	int M, N;
//	Node** head;
//	Node** tail;
//public:
//	SparseMatrix()
//	{
//		for (int i = 0; i < M; i++)
//		{
//			this->head[i] = NULL;
//			this->tail[i] = NULL;
//		}
//	}
//
//	SparseMatrix(string filename)
//	{
//		this->read(filename);
//	}
//
//	void read(string filename)
//	{
//		ifstream input;
//		input.open(filename + ".txt");
//
//		int row = 0, col = 0, rowcount = 0, colcount = 0;
//		char matrix;
//
//		if (input.is_open())
//		{
//			input >> row;
//			input >> col;
//			M = row;
//			N = col;
//			head = new Node * [M];
//			tail = new Node * [M];
//			for (int i = 0; i < M; i++)
//			{
//				head[i] = NULL;
//				tail[i] = NULL;
//			}
//			while (rowcount != M) {
//				input >> matrix;
//
//				if (matrix >= 48 || matrix <= 57)
//				{
//
//					if (matrix != 48)
//					{
//						if (head[rowcount] == NULL)
//						{
//							Node* newnode = new Node;
//							newnode->value = matrix - 48;
//							newnode->colindex = colcount;
//							head[rowcount] = newnode;
//							newnode->nextInRow = NULL;
//							tail[rowcount] = newnode;
//						}
//						else
//						{
//							Node* newnode = new Node;
//							newnode->value = matrix - 48;
//							newnode->colindex = colcount;
//							tail[rowcount]->nextInRow = newnode;
//							tail[rowcount] = newnode;
//							newnode->nextInRow = NULL;
//						}
//					}
//					colcount++;
//
//
//				}
//				if (colcount == N)
//				{
//					colcount = 0;
//					rowcount++;
//				}
//
//			}
//		}
//		input.close();
//
//	}
//
//	SparseMatrix(const SparseMatrix& obj)
//	{
//
//		this->M = obj.M;
//		this->N = obj.N;
//
//		this->head = new Node * [M];
//		this->tail = new Node * [M];
//		for (int i = 0; i < M; i++)
//		{
//			this->head[i] = NULL;
//			this->tail[i] = NULL;
//		}
//		Node* temp1 = new Node[M];
//		Node* temp2 = new Node[M];
//
//		for (int i = 0; i < M; i++)
//		{
//			temp1 = obj.head[i];
//			temp2 = obj.tail[i];
//
//			while (temp1 != NULL)
//			{
//				if (this->head[i] == NULL)
//				{
//					Node* newnode = new Node;
//					newnode->value = temp1->value;
//					newnode->colindex = temp1->colindex;
//					newnode->nextInRow = NULL;
//					this->head[i] = newnode;
//					this->tail[i] = newnode;
//				}
//				else {
//					Node* newnode = new Node;
//					newnode->value = temp1->value;
//					newnode->colindex = temp1->colindex;
//					this->tail[i]->nextInRow = newnode;
//					this->tail[i] = newnode;
//					newnode->nextInRow = NULL;
//				}
//				temp1 = temp1->nextInRow;
//			}
//		}
//
//	}
//
//	const SparseMatrix& operator = (const SparseMatrix& obj)
//	{
//
//		this->M = obj.M;
//		this->N = obj.N;
//
//		this->head = new Node * [M];
//		this->tail = new Node * [M];
//		for (int i = 0; i < M; i++)
//		{
//			this->head[i] = NULL;
//			this->tail[i] = NULL;
//		}
//		Node* temp1 = new Node[M];
//		Node* temp2 = new Node[M];
//
//		for (int i = 0; i < M; i++)
//		{
//			temp1 = obj.head[i];
//			temp2 = obj.tail[i];
//
//			while (temp1 != NULL)
//			{
//				if (this->head[i] == NULL)
//				{
//					Node* newnode = new Node;
//					newnode->value = temp1->value;
//					newnode->colindex = temp1->colindex;
//					newnode->nextInRow = NULL;
//					this->head[i] = newnode;
//					this->tail[i] = newnode;
//				}
//				else {
//					Node* newnode = new Node;
//					newnode->value = temp1->value;
//					newnode->colindex = temp1->colindex;
//					this->tail[i]->nextInRow = newnode;
//					this->tail[i] = newnode;
//					newnode->nextInRow = NULL;
//				}
//				temp1 = temp1->nextInRow;
//			}
//		}
//
//
//		return *this;
//	}
//
//	SparseMatrix operator + (const SparseMatrix& obj)
//	{
//		SparseMatrix objAdd;
//		objAdd.M = this->M;
//		objAdd.N = this->N;
//		if (this->M == obj.M && this->N == obj.N)
//		{
//
//			objAdd.head = new Node * [M];
//			objAdd.tail = new Node * [M];
//			for (int i = 0; i < M; i++)
//			{
//				objAdd.head[i] = NULL;
//				objAdd.tail[i] = NULL;
//			}
//
//			Node* temphead1 = new Node;
//			Node* temptail1 = new Node;
//
//			Node* temphead2 = new Node;
//			Node* temptail2 = new Node;
//
//
//			for (int i = 0; i < M; i++)
//			{
//				temphead1 = this->head[i];
//				temptail1 = this->tail[i];
//
//				temphead2 = obj.head[i];
//				temptail2 = obj.tail[i];
//
//				while (temphead1 != NULL || temphead2 != NULL)
//				{
//					if (objAdd.head[i] == NULL)
//					{
//						Node* newnode = new Node;
//
//						if (temphead1 == NULL && temphead2 != NULL)
//						{
//							newnode->value = temphead2->value;
//							newnode->colindex = temphead2->colindex;
//							temphead2 = temphead2->nextInRow;
//
//						}
//
//
//						else if (temphead2 == NULL && temphead1 != NULL)
//						{
//							newnode->value = temphead1->value;
//							newnode->colindex = temphead1->colindex;
//							temphead1 = temphead1->nextInRow;
//
//						}
//						else if (temphead1->colindex == temphead2->colindex)
//						{
//							newnode->value = temphead1->value + temphead2->value;
//							newnode->colindex = temphead1->colindex;
//							temphead1 = temphead1->nextInRow;
//							temphead2 = temphead2->nextInRow;
//						}
//						else if (temphead1->colindex != temphead2->colindex)
//						{
//							if (temphead1->colindex > temphead2->colindex)
//							{
//								newnode->value = temphead2->value;
//								newnode->colindex = temphead2->colindex;
//								temphead2 = temphead2->nextInRow;
//
//							}
//							else if (temphead1->colindex < temphead2->colindex)
//							{
//								newnode->value = temphead1->value;
//								newnode->colindex = temphead1->colindex;
//								temphead1 = temphead1->nextInRow;
//							}
//
//						}
//						newnode->nextInRow = NULL;
//						objAdd.head[i] = newnode;
//						objAdd.tail[i] = newnode;
//					}
//					else
//					{
//						Node* newnode = new Node;
//
//						if (temphead1 == NULL && temphead2 != NULL)
//						{
//							newnode->value = temphead2->value;
//							newnode->colindex = temphead2->colindex;
//							temphead2 = temphead2->nextInRow;
//
//						}
//						else if (temphead2 == NULL && temphead1 != NULL)
//						{
//							newnode->value = temphead1->value;
//							newnode->colindex = temphead1->colindex;
//							temphead1 = temphead1->nextInRow;
//
//						}
//						else if (temphead1->colindex == temphead2->colindex)
//						{
//							newnode->value = temphead1->value + temphead2->value;
//							newnode->colindex = temphead1->colindex;
//							temphead1 = temphead1->nextInRow;
//							temphead2 = temphead2->nextInRow;
//
//						}
//						else if (temphead1->colindex != temphead2->colindex)
//						{
//							if (temphead1->colindex > temphead2->colindex || temphead1 == NULL)
//							{
//								newnode->value = temphead2->value;
//								newnode->colindex = temphead2->colindex;
//									temphead2 = temphead2->nextInRow;
//							}
//							else if (temphead1->colindex < temphead2->colindex || temphead2 == NULL)
//							{
//								newnode->value = temphead1->value;
//								newnode->colindex = temphead1->colindex;
//									temphead1 = temphead1->nextInRow;
//							}
//
//
//						}
//						objAdd.tail[i]->nextInRow = newnode;
//						objAdd.tail[i] = newnode;
//						newnode->nextInRow = NULL;
//					}
//
//
//				}
//
//			}
//		}
//
//		return objAdd;
//	}
//	
//
//	SparseMatrix& inverse()
//	{
//		SparseMatrix inverseobj;
//
//		inverseobj.M = this->M;
//		inverseobj.N = this->N;
//
//		inverseobj.head = new Node * [M];
//		inverseobj.tail = new Node * [M];
//		for (int i = 0; i < M; i++)
//		{
//			inverseobj.head[i] = NULL;
//			inverseobj.tail[i] = NULL;
//		}
//
//		int det = 0;
//		det = ((this->head[1]->value) * (this->tail[0]->value)) - ((this->head[0]->value) * (this->tail[1]->value));
//		if (det == 0)
//		{
//			cout << "Inverse not possible\n";
//			exit(0);
//		}
//		Node* temp;
//
//		for (int i = 0; i < M; i++)
//		{
//			temp = this->head[i];
//			for (int j = N - 1; j >= 0; j--)
//			{
//				Node* newnode = new Node;
//				if (inverseobj.head[i] == NULL)
//				{
//					if (i == 0)
//						newnode->value = this->tail[j]->value;
//					else if (i == 1)
//						newnode->value = -this->head[j]->value;
//
//					newnode->colindex = i;
//					newnode->nextInRow = NULL;
//					inverseobj.tail[i] = newnode;
//					inverseobj.head[i] = newnode;
//				}
//				else
//				{
//					if (i == 0)
//					{
//						newnode->value = -this->tail[j]->value;
//					}
//					else if (i == 1)
//					{
//						newnode->value = this->head[j]->value;
//
//					}
//					inverseobj.tail[i]->nextInRow = newnode;
//					inverseobj.tail[i] = newnode;
//					newnode->nextInRow = NULL;
//					newnode->colindex = 1;
//				}
//
//			}
//		}
//
//		cout << endl;
//		Node* temp1;
//		for (int i = 0; i < M; i++)
//		{
//			temp1 = inverseobj.head[i];
//			while (temp1 != NULL)
//			{
//				temp1->value = (temp1->value) / det;
//				temp1 = temp1->nextInRow;
//			}
//		}
//
//		inverseobj.print();
//
//		return inverseobj;
//	}
//	SparseMatrix& transpose()
//	{
//		SparseMatrix tr;
//		tr.M = this->N;
//		tr.N = this->M;
//
//		tr.head = new Node * [M];
//		tr.tail = new Node * [M];
//		for (int i = 0; i < M; i++)
//		{
//			tr.head[i] = NULL;
//			tr.tail[i] = NULL;
//		}
//		Node* temp;
//
//		for (int i = 0; i < M; i++)
//		{
//			temp = head[i];
//			for (int j = 0; j < N; j++)
//			{
//				if (temp == NULL)
//					break;
//				if (tr.head[temp->colindex] == NULL)
//				{
//					Node* newnode = new Node;
//					newnode->value = temp->value;
//					newnode->colindex = i;
//					newnode->nextInRow = NULL;
//					tr.head[temp->colindex] = newnode;
//					tr.tail[temp->colindex] = newnode;
//				}
//				else
//				{
//					Node* newnode = new Node;
//					newnode->value = temp->value;
//					newnode->colindex = i;
//					tr.tail[temp->colindex]->nextInRow = newnode;
//					tr.tail[temp->colindex] = newnode;
//					newnode->nextInRow = NULL;
//				}
//				
//				temp = temp->nextInRow;
//			}
//
//		}
//		*this = tr;
//		return *this;
//	}
//	
//	SparseMatrix& operator * (SparseMatrix& obj)
//	{
//
//	     this->transpose();
//		 SparseMatrix product;
//		 product.M = this->M;
//		 product.N = this->N;
//
//		 product.head = new Node * [M];
//		 product.tail = new Node * [M];
//
//		 for (int i = 0; i < M; i++)
//		 {
//			 product.head[i] = NULL;
//			 product.tail[i] = NULL;
//		 }
//
//		 if (this->M != obj.M)
//		 {
//			 cout << "Multiplication not possible\n";
//			 exit(0);
//		 }
//		 
//		 else
//		 {
//			 int sum = 0;
//			 Node* temp1,*temp2;
//			 for (int i = 0; i < product.M; i++)
//			 {
//				 for (int j = 0; j < this->M; j++)
//				 {
//					 temp1 = this->head[i];
//					 temp2 = obj.head[j];
//					 sum = 0;
//					 while (temp1 != NULL && temp2 != NULL)
//					 {
//						 if (temp1->colindex == temp2->colindex)
//						 {
//							 sum = (temp1->value * temp2->value) + sum;
//							 temp1 = temp1->nextInRow;
//							 temp2 = temp2->nextInRow;
//
//						 }
//						 else if (temp1->colindex > temp2->colindex)
//						 {
//							 temp2 = temp2->nextInRow;
//						 }
//						 else if (temp1->colindex < temp2->colindex)
//						 {
//							 temp1 = temp1->nextInRow;
//						 }
//
//					 }
//
//					 if (sum != 0)
//					 {
//						 Node* newnode = new Node;
//						 newnode->value = sum;
//						 newnode->colindex = j + 1;
//						 if (product.head[i] == NULL)
//						 {
//							 product.head[i] = newnode;
//						 }
//						 else
//						 {
//							 product.tail[i]->nextInRow = newnode;
//						 }
//						 product.tail[i] = newnode;
//
//						 newnode->nextInRow = NULL;
//
//					 }
//				 }
//			 }
//		 }
//
//		
//		 *this = product;
//
//		 return *this;
//	}
//	SparseMatrix& minus()
//	{
//
//		Node* temp;
//		for (int i = 0; i < M; i++)
//		{
//			temp = this->head[i];
//			while (temp != NULL)
//			{
//				temp->value = -temp->value;
//				temp = temp->nextInRow;
//			}
//		}
//		return *this;
//	}
//	bool symmetric()
//	{
//		SparseMatrix sym;
//		sym = *this;
//		sym.transpose();
//
//		Node* temp1, * temp2;
//		if (sym.M == this->M && sym.N == this->N)
//		{
//			for (int i = 0; i < M; i++)
//			{
//				temp1 = sym.head[i];
//				temp2 = this->head[i];
//
//				while (temp1 != NULL && temp2 != NULL)
//				{
//					if (temp1->value != temp2->value || temp1->colindex != temp2->colindex )
//					{
//						cout << "Not a symmetric matrix\n";
//						return false;
//					}
//					else
//					{
//						temp1 = temp1->nextInRow;
//						temp2 = temp2->nextInRow;
//					}
//				}
//			}
//			cout << "Is a symmetric matrix\n";
//			return true;
//		}
//		else
//		{
//			cout << "Not a symmetric matrix\n";
//			return false;
//		}
//
//	}
//	bool skewsymmetric()
//	{
//
//		SparseMatrix skew;
//		skew = *this;
//		skew.transpose();
//		this->minus();
//		skew.minus();
//		Node* temp1, * temp2;
//		if (skew.M == this->M && skew.N == this->N)
//		{
//			for (int i = 0; i < M; i++)
//			{
//				temp1 = skew.head[i];
//				temp2 = this->head[i];
//
//				while (temp1 != NULL && temp2 != NULL)
//				{
//					if (temp1->value != temp2->value || temp1->colindex != temp2->colindex)
//					{
//						cout << "Not a skew symmetric matrix\n";
//						return false;
//					}
//					else
//					{
//						temp1 = temp1->nextInRow;
//						temp2 = temp2->nextInRow;
//					}
//				}
//			}
//			cout << "Is a skew symmetric matrix\n";
//			return true;
//		}
//		else
//		{
//			cout << "Not a skew symmetric matrix\n";
//			return false;
//		}
//	}
//	void print() {
//		for (int i = 0; i < M; i++) {
//			Node* temp;
//			temp = head[i];
//			cout << "row[" << i + 1 << "] =>";
//			if (temp == NULL) {
//				cout << "NULL";
//			}
//			while (temp != NULL) {
//				int a = temp->value;
//				cout << "[" << temp->colindex+1 << " , " << a << "] ==>";
//				temp = temp->nextInRow;
//			}
//
//			cout << "\b\b\b";
//			cout << "   ";
//			cout << endl;
//		}
//		cout << endl;
//	}
//	~SparseMatrix()
//	{
//
//		for (int i = 0; i < M; i++)
//		{
//			if (head[i] != NULL) {
//				Node* temp;
//				temp = head[i]->nextInRow;
//				while (temp != NULL)
//				{
//					delete head[i];
//					head[i] = temp;
//					temp = temp->nextInRow;
//
//
//				}
//				delete temp;
//			}
//
//		}
//	}
//};
//
//int main()
//{
//	SparseMatrix obj1("sparse");
//	cout << "The sparse matrix is: \n";
//	obj1.print();
//
//	SparseMatrix obj2 = obj1;
//	cout << "The copy constructor is: \n";
//	obj2.print();
//
//	obj2 = obj1;
//	cout << "The assignment operator is: \n";
//	obj2.print();
//
//	cout << "Add function for test case 1\n";
//	SparseMatrix obj3("ADD3");
//	SparseMatrix objADD;
//	SparseMatrix obj4("ADD4");
//	objADD = obj4 + obj3;
//	cout << "The + operator is: \n";
//	objADD.print();
//
//	cout << "Add function for test case2\n";
//	SparseMatrix obj5("ADD1");
//	SparseMatrix obj6("ADD2");
//	SparseMatrix objAdd2;
//	objAdd2 = obj5 + obj6;
//	objAdd2.print();
//
//
//	SparseMatrix obj8("symmetric");
//	obj8.symmetric();
//
//	
//	SparseMatrix obj9("symmetric");
//	obj9.symmetric();
//
//	obj9.skewsymmetric();
//	obj9.print();
//
//	cout << "\nMultiplication is :\n";
//	SparseMatrix obj10("multiply");
//	obj10*obj1;
//	obj10.print();
//
//
//	cout << "\nThe inverse function is: ";
//	SparseMatrix obj7("INVERSE1");
//	obj7.inverse();
//
//	return 0;
//}
#include <iostream>
using namespace std;

template<class T>
class QNode
{
	private:
		T data;
		QNode<T> *next;
	public:
		QNode(T e)
		{
			data = e;
			next = NULL;
		}
		friend class QStack;
};

class QStack
{
	private:
		QNode<int> *top;
		int n, capacity;
	public:
		QStack(int size)
		{
			top = NULL;
			n = 0;
			capacity = size;
		}

		bool empty()
		{
			return  (top==NULL);
		}
		
		int size()
		{
			return n;
		}

		int peek()
		{
			return top->data;
		}
		
		void push(int e)	
		{
			QNode<int> *p = new QNode<int>(e);
			if (n == capacity)
			{
				cout << "Stack Overflow\n";
			}
			else if (top == NULL)
			{
				top = p;
				n++;
			}
			else
			{
				p->next = top;
				top=p;
				n++;
			}	
			//:) Hehehehe
		}
		
		int pop()
		{
			if(empty())
			{
				cout<< " stack is empty"<<endl;
				return -1;
			}
			else
			{
				int x = top->data;
				top = top->next;
				n--;
				return (x); 
			}
			//:) Hehehe
		}
		void display()
		{
			QNode<int> *temp = top;
			cout << "Stack Elements\n";
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			//:) Hehe
		} 
};

void mainMenu(QStack S)
{
	char ch;
	do
	{
		ch='y';
		int choice;
		cout<<"---------------- MAIN MENU ----------------"<<endl;
		cout<<"1. Push "<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peek"<<endl;
		cout<<"4. Display"<<endl;
		cout<<"Enter your choice (1-4)"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1:
			{
				int el;
				cout<<"Enter element: ";
				cin>>el;
				S.push(el);
				break;
			}
			case 2:
			{			
				cout << "Element removed " << S.pop();
				break;
			}
			case 3:
			{
				cout << "Element at top " << S.peek();
				break;	
			}
			case 4:
			{
				S.display();
				break;
			}
		}
		cout<<endl<<"Do you wish to continue ?"<<endl;
		cin>>ch;
		cout<<endl;
		cout<<"-----------------------------------------"<<endl;
		if(ch=='y' || ch=='Y')
			continue;
		else
			exit(0);
    }while(ch=='y' || ch=='Y');
}

int main() 
{
	int s;
	cout<<"Enter capacity of stack: ";
	cin >> s;
	QStack S(s);
	mainMenu(S);
};

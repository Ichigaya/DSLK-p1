#include <iostream>
using namespace std;

struct PHANSO
{
	int tu, mau;
};

typedef struct Node* node;
struct Node
{
	PHANSO key;
	node next;
};

istream &operator>>(istream &inDev, PHANSO &x)
{
	do
	{
		inDev >> x.tu >> x.mau;
		if (x.mau == 0) cout << "Nhap loi! Nhap lai!" << endl;
	} while (x.mau == 0);
	return inDev;
}

ostream &operator<<(ostream &outDev, PHANSO x)
{
	if ((x.tu == 0) || (x.mau == 1)) outDev << x.tu << " ";
	else
	if (x.tu%x.mau == 0) outDev << x.tu / x.mau << " ";
	else 
	outDev << x.tu << "/" << x.mau << " ";
	return outDev;
}

node getnode(PHANSO k)
{
	node p;
	p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho!";
		return NULL;
	}
	p->key = k;
	p->next = NULL;
	return p;
}

void addLast(node &head, node &tail, PHANSO k)
{
	node p;
	p = getnode(k);
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

void getArr(node &head, node &tail)
{
	PHANSO k;
	cout << "Nhap cac phan tu (nhap x de thoat): " << endl;
	while (cin >> k)
		addLast(head, tail, k);
}

void printlist(node head)
{
	if (head == NULL)
		cout << "Danh sach rong!" << endl;
	else
	{
		node p;
		for (p = head; p; p = p->next)
			cout << p->key;
		cout << endl;
	}
}

void insertAfter(node q, PHANSO k)
{
	node p;
	p = new Node;
	p = getnode(k);
	p->next = q->next;
	q->next = p;
}


void insertBefore(node q, PHANSO k)
{
	node p;
	p = new Node;
	*p = *q;
	q->next = p;
	q->key = k;
}


void Insert(node head, node tail, int p, PHANSO t)
{
	if (p == 0) insertBefore(head, t);
	else
	{
		node q = head;
		int i = 1;
		while ((q->next != NULL) && (i < p))
		{
			q = q->next;
			i++;
		}
		insertAfter(q, t);
	}
}

void main()
{
	PHANSO t;
	int p;
	node head = NULL, tail = NULL;
	getArr(head, tail);
	printlist(head);
	cout << "Nhap vao phan so can chen vao danh sach: " << endl;
	cin.clear();
	cin.ignore(10, '\n');
	cin >> t;
	cout << "Nhap vao vi tri can chen: " << endl;
	cin >> p;
	Insert(head, tail, p, t);
	printlist(head);
	system("pause");
}
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


void Insert(node &head, node &tail, int p, PHANSO t)
{
	if (p == 0) insertBefore(head, t);
	else
	{
		node q = head;
		int i = 0;
		while ((q->next != NULL) && (i < p))
		{
			q = q->next;
			i++;
		}
		insertAfter(q, t);
		if (q == tail) tail = q->next;
	}
}

int length(node head)
{
	node q;
	int count = 0;
	for (q = head; q; q = q->next)
		count++;
	return count;
}

void deleteBegin(node &head, node &tail)
{
	node q;
	if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		q = head;
		head = head->next;
		free(q);
	}
}

void deleteEnd(node &head, node &tail)
{
	node q;
	if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		for (q = head; q->next != tail; q = q->next);
		free(tail);
		tail = q;
		q->next = NULL;
	}
}

void deleteMiddle(node q)
{
	node p;
	p = q->next;
	*q = *p;
	free(p);
}

void DeleteAt(node &head, node &tail, int pos)
{
	int n, i;
	node q;
	n = length(head);
	if ((pos < 0) || (pos >= n))
	{
		cout << "Vi tri khong phu hop" << endl;
		return;
	}
	if (pos == 0) deleteBegin(head, tail);
	else
	if (pos == n - 1) deleteEnd(head, tail);
	else
	{
		for (i = 0, q = head; i < pos; i++, q = q->next);
		if (q->next = tail) tail = q;
		deleteMiddle(q);
	}
}

void DestroyList(node &head)
{
	node q;
	while (head)
	{
		q = head;
		head = head->next;
		free(q);
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
	cout << "Nhap vao vi tri can xoa: " << endl;
	cin >> p;
	DeleteAt(head, tail, p);
	printlist(head);
	cout << "Nhan enter de huy toan bo danh sach...";
	cin.ignore();
	cin.get();
	DestroyList(head);
	cout << "Da huy danh sach!" << endl;
	system("pause");
}
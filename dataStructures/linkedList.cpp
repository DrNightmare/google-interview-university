#include "iostream"

using namespace std;

struct node {
	int data;
	node *next;

	node(int x, node *n) {
		data = x;
		next = n;
	}
};

typedef node* link;

class linkedList
{
private:
	link head, tail;
	int n;
public:
	linkedList() {
		head = tail = NULL;
		n = 0;
	}

	int size() {
		return n;
	}

	bool empty() {
		return n == 0;
	}

	int value_at(int index) {
		if (index < 0 || index > n - 1) return -1;
		int i = 0;
		link temp = head;
		while(i < index) temp = temp->next;
		return temp->data;
	}

	void push_front(int value) {
		head = new node(value, head);
		n++;
		if (n == 1) tail = head;
	}
	
	void push_back(int value) {
		if (n == 0) {
			tail = new node(value, NULL);
			head = tail;
		}
		else {
			tail->next = new node(value, NULL);
			tail = tail->next;
		}
		n++;
	}

	int pop_front() {
		if (head == NULL) return -1;
		link temp = head;
		int front_data = temp->data;
		head = head->next;
		delete temp;
		n--;
		return front_data;
	}

	int front() {
		return head->data;
	}

	int back() {
		return tail->data;
	}
};

int main() {
	linkedList testList;

	testList.push_back(3);
	testList.push_front(1);
	testList.push_front(4);
	testList.push_back(5);
	testList.push_back(3);
	cout << testList.pop_front() << '\n';
	cout << testList.front() << '\n';
	cout << testList.back() << '\n';
	cout << testList.size() << '\n';
	return 0;
}
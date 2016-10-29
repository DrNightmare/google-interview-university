#include "iostream"

using namespace std;

class vector
{
private:
	int data[20];
	int n;
public:
	vector() {
		n = 0;
	}
	
	int size() {
		return n;
	}

	int capacity() {
		return 20;
	}

	int is_empty() {
		return n == 0;
	}

	int at(int index) {
		if (index < 0 || index > n - 1) return -1;
		return data[index];
	}

	void push(int item) {
		if (n == capacity()) return;
		data[n++] = item;
	}

	void insert(int index, int item) {
		if (index < 0 || index > n || n == capacity()) return;
		for(int i = n; i > index; i--)
			data[i] = data[i - 1];
		data[index] = item;
		n++;
	}

	int pop() {
		return data[--n];
	}

	void prepend(int item) {
		insert(0, item);
	}

	void deleteAt(int index) {
		if (index < 0 || index > n - 1 || n == capacity()) return;
		for(int i = index; i < n - 1; i++)
			data[i] = data[i + 1];
		n--;
	}

	void remove(int item) {
		for(int i = 0; i < n; i++) {
			if (data[i] == item) {
				deleteAt(i);
				i--;
			}
		}
	}

	int find(int item) {
		for(int i = 0; i < n; i++)
			if (data[i] == item) return i;
		return -1;
	}
};

int main() {
	vector testvect;
	testvect.push(4);
	testvect.push(2);
	testvect.push(1);
	testvect.push(7);
	testvect.push(15);
	
	cout << testvect.find(7) << '\n';
	return 0;
}
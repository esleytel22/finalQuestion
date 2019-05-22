#include <iostream>
using namespace std;

class z {
public:
	z() {
		cout << "z: enter " << endl;
	}
	~z() {
		cout << "z: exit " << endl;
	}
};
class X {
	int i;
	int j;
public:
	void destroy();
	virtual ~X() {
		z a;
		cout << "X's dtor\n"; //POINT 1
	}
};

void X::destroy() {
	z a;
	delete this;
}

class Y : public X {
	int *j;
public :
	Y() {
		j = new int;
	}
	~Y() {
		z a;
		cout << "Y's dtor\n";
		delete j;
	}
};

int main() {
	X* x = new Y;
	cout << "going to destroy" << endl;
	x->destroy();
	cout << "froom main: Do we all destructors?" << endl;
	cin.get();
}

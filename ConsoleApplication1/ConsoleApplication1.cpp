#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;


int main() {
	int a;
	int b;
	int o;
	cin >> a;
	cin >> b;
	cin >> o;
	switch (o)
	{
	case 1:
		cout << a + b << endl;
		break;
	case 2:
		cout << a - b << endl;
		break;
	case 3:
		cout << a * b << endl;;
		break;
	case 4:
		cout << a / b << endl;
		break;
	}
}
#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int argc, ...)
{
	va_list va;
	va_start(va, argc);

	int s = 0;
	for (int i = 0; i < argc; i++)
	{
		s += va_arg(va, int);
	}
	va_end(va, argc);
	return s;
}

int main()
{
	cout << sum(3, 5, 3, 2) << endl;
	return 0;
}
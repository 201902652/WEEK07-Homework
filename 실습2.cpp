#include <iostream>
// /*
bool funcA() {
	int c;
	std::cout << "input(Number) : ";
	std::cin >> c;
	if (c < 10) {
		throw std::out_of_range("Exception: Invalid Input! ");
	}
	return true;
}

int main() {
	try {
		funcA();
	}
	catch (std::exception e) {
		std::cout << "Exception Occured: " << e.what() << std::endl;
	}
	return 0;
}
// */
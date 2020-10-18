#include <iostream>
#include <stdexcept>
/*
class Test {
public:
	Test (char id) : id_(id){}
	~Test() { std::cout << "Destructor Execution: " << id_ << std::endl; }

private:
	char id_;
};

int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}

/*�ǽ� 1-1 �м����

class Test -> private �ʵ忡 ���ڿ��� �����ϴ� ���� id_ �� �����
Test(char id) -> private ���� id_�� �Է¹��� ���� id�� ������ ��ü ����
������ ���� �� "Destructor Execution: + ���� id_�� ����"�� ���

funcA(), funcB() -> ���� ������ ���� ����. funcA()�� ��쿡�� funcB()�� ���� �� ������ ���� ����

1) funcA() �Լ� ����
2) char A�� �Է¹��� Test ��ü ����
3) funcB() �Լ� ����
4) char B�� �Է¹��� Test ��ü ����
5) funcB()���� ������ ��� 'Executed in B' ��� �� �۵� �Ϸ�
6) funcB() �۵� �Ϸ� �� funcA()�� ���� ���� 'Executed in A' ��� �� �۵� �Ϸ�
7) main() �Լ� �۵� �Ϸ�

- main()���� funcA()��, funcA()���� funcB()�� �Լ� ���η� ������ ������ ����� ������ ����, ���� �Ϸ��� ������� ���ʴ�� �Լ� �ܺη� �������� �� ����� �����Ѵ�.
main() -> funcA() -> funcB() -> funcA() -> main()
�Լ� ���� ���� exception�� �߻����� �ʾ����Ƿ� catch ���� ������ �ʿ� ���� �״�� ���α׷� ���� ����.

*/

/*�ǽ� 1-2 �м����

funcB()���� ������ ���� ��� ������ throw�� ������ ���������Ƿ�, ����� �Լ����� ���� ����� catch���� ã�� �ȴ�.
catch���� ã�� ���� funcB()�� ������ ���, funcA()���� funcB() ȣ�� ������ ��� ����� catch���� ã�� ������ ���õȴ�.
catch���� main()�� funcA() �Լ� ȣ�� ���Ŀ� ���ǵǾ� �����Ƿ�, funcA(), funcB()�� Destructor execution ������ ����� ��, funcB()�� throw���� ����
������ �̿��� ���� ������ �ϰ� �ȴ�.
�� �� funcB()������ throw ���� ������ std::runtime_error�� �����߰�, main()�� catch�� std::exception Ÿ���� �����Ƿ�, funcB()���� ����� ������ main()�� catch������ �޾����� �ȴ�.
���� catch���� ����(���� ���� + ������ ���� ���� ���� "Exception from funcB!\n")�� ����� �� ���α׷� ������ �����Ѵ�.

��, Ư�� �Լ����� ������ ����Ǹ�, �� �Լ��κ��� ���� ����� catch���� ã�� ���� ������ �Ž��� ���鼭 ã�� �ǰ�
catch���� ã�� catch���� ������ ������ ��, catch �� ������ �������� �����ϰ� �ȴ�.

*/
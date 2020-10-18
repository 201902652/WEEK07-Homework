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

/*실습 1-1 분석결과

class Test -> private 필드에 문자열을 저장하는 변수 id_ 가 선언됨
Test(char id) -> private 변수 id_에 입력받은 변수 id를 저장해 객체 생성
생성자 생성 시 "Destructor Execution: + 변수 id_의 내용"을 출력

funcA(), funcB() -> 각각 지정된 문구 실행. funcA()의 경우에는 funcB()를 실행 후 지정된 문구 실행

1) funcA() 함수 실행
2) char A를 입력받은 Test 객체 생성
3) funcB() 함수 실행
4) char B를 입력받은 Test 객체 생성
5) funcB()에서 지정된 명령 'Executed in B' 출력 후 작동 완료
6) funcB() 작동 완료 후 funcA()의 다음 구문 'Executed in A' 출력 후 작동 완료
7) main() 함수 작동 완료

- main()에서 funcA()로, funcA()에서 funcB()로 함수 내부로 진입해 지정한 명령을 실행한 다음, 실행 완료한 순서대로 차례대로 함수 외부로 빠져나온 후 명령을 실행한다.
main() -> funcA() -> funcB() -> funcA() -> main()
함수 실행 동안 exception이 발생하지 않았으므로 catch 문은 실행할 필요 없이 그대로 프로그램 실행 종료.

*/

/*실습 1-2 분석결과

funcB()에서 지정된 문구 출력 이전에 throw로 오류를 선언했으므로, 실행된 함수에서 가장 가까운 catch문을 찾게 된다.
catch문을 찾을 동안 funcB()의 나머지 명령, funcA()에서 funcB() 호출 이후의 모든 명령은 catch문을 찾을 때까지 무시된다.
catch문이 main()의 funcA() 함수 호출 이후에 정의되어 있으므로, funcA(), funcB()의 Destructor execution 문구를 출력한 후, funcB()의 throw에서 받은
오류를 이용해 오류 선언을 하게 된다.
이 때 funcB()에서는 throw 오류 선언을 std::runtime_error로 선언했고, main()의 catch는 std::exception 타입을 받으므로, funcB()에서 선언된 오류가 main()의 catch문에서 받아지게 된다.
이후 catch문의 문구(오류 선언 + 오류를 던진 곳의 내용 "Exception from funcB!\n")를 출력한 후 프로그램 실행을 종료한다.

즉, 특정 함수에서 오류가 선언되면, 그 함수로부터 가장 가까운 catch문을 찾기 위해 스택을 거슬러 가면서 찾게 되고
catch문을 찾아 catch문의 내용을 실행한 후, catch 문 다음의 문구부터 실행하게 된다.

*/
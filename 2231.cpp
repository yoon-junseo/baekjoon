/*
접근법  1. 생성자는 입력받은 숫자 보다 작다->for문으로 n까지만
		2. % 연산자와 / 연산자를 활용해서 각 자릿수를 구하고 sum에 더한다.
		3. sum과 입력받은 숫자가 같으면 출력하고 프로그램 종료.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	int sum = 0;
	int digitNum = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		sum = i;
		digitNum = i;

		while (digitNum) {
			sum += digitNum % 10;
			digitNum /= 10;
		}

		if (sum == n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0;
	return 0;
}
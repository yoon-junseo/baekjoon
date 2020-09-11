#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	int n = 0; // 몇 줄 입력할건지
	cin >> n;
	int num = 0; // 숫자야구의 숫자
	int strike = 0;
	int ball = 0;
	int tStr = 0; // 체크할 strike
	int tBall = 0;
	int result = 0;
	string testNum;
	string temp;
	string aaa;

	bool ans[1000]; // 정답이 담길 배열
	for (int i = 0; i < 1000; i++) {
		ans[i] = true; // true로 초기화
	}
	
	// 123~987까지 조건에 맞는 숫자만 배열에 담아두기 (0이 아니고 각 자리의 숫자가 같으면 안된다)
	for (int i = 123; i <= 987; i++) {
		temp = to_string(i);
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') {
			ans[i] = false;
		}
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) {
			ans[i] = false;
		}
	}
	
	for (int l = 0; l < n; l++) {
		cin >> num >> strike >> ball; // 질문 입력받기
		for (int i = 123; i <= 987; i++) {
			tStr = 0;
			tBall = 0;
			testNum = to_string(num);
			aaa = to_string(i);

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (testNum[j] == aaa[k] && j == k) {
						tStr++;
					}
					else if (testNum[j] == aaa[k] && j != k) {
						tBall++;
					}
				}
			}
			if (tStr != strike || tBall != ball) {
				ans[i] = false;
			}
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (ans[i] == true)
			result++;
	}
	
	cout << result;
	
	return 0;
}
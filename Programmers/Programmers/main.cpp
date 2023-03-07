
#include "main.h"

// *** 이진수 더하기 ***
//이진수를 의미하는 두 개의 문자열 bin1과 bin2가 매개변수로 주어질 때, 
//두 이진수의 합을 return하도록 solution 함수를 완성해주세요.
string solution(string bin1, string bin2) {
	string answer = "";
	int carry_bit = 0;		// 자리 올림수

	// 이진 bit 길이 같도록 Set
	if (bin1.length() < bin2.length())
	{
		bin1 = string(bin2.length() - bin1.length(), '0') + bin1;
	}
	else if (bin2.length() < bin1.length())
	{
		bin2 = string(bin1.length() - bin2.length(), '0') + bin2;
	}

	// 끝에서 부터 계산
	for (int i = bin1.length()-1; i >= 0; i--)
	{
		int sum = stoi(to_string(bin1[i] - '0')) + stoi(to_string(bin2[i] - '0')) + carry_bit;
		carry_bit = sum / 2;

		answer = to_string(sum % 2) + answer;
	}
	
	// 자리 올림수 있다면 맨앞에 1 추가
	if (carry_bit == 1)
	{
		answer = '1' + answer;
	}

	return answer;
}

// *** 소인수분해 ***
//소인수분해란 어떤 수를 소수들의 곱으로 표현하는 것입니다.
//예를 들어 12를 소인수 분해하면 2 * 2 * 3 으로 나타낼 수 있습니다. 따라서 12의 소인수는 2와 3입니다.
//자연수 n이 매개변수로 주어질 때 n의 소인수를 오름차순으로 담은 배열을 return하도록 solution 함수를 완성해주세요.

vector<int> solution(int n) {
	vector<int> answer;
	int num = 2;

	while (true)
	{
		// 더이상 나눌 분해가 없을 시 반복문 stop
		if (n == 1)
		{
			break;
		}
		// 나누기
		else if (n%num == 0)
		{
			n = n / num;

			auto it = find(answer.begin(), answer.end(), num);
			if (it == answer.end())
			{
				// 배열에 넣을 시 값이 존재하는지 확인
				answer.push_back(num);
			}
			// 나누기는 2부터
			num = 2;
		}
		else
		{	//나누기가 되지 않는 다면 나눌 값 올리기
			num++;
		}
	}

	return answer;
}


void main()
{
	solution("100", "100");

	return;
}
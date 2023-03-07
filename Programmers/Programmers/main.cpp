
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


void main()
{
	solution("100", "100");

	return;
}
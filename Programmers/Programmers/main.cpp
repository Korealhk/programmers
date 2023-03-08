
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

//7의 개수
//머쓱이는 행운의 숫자 7을 가장 좋아합니다.
//정수 배열 array가 매개변수로 주어질 때, 7이 총 몇 개 있는지 return 하도록 solution 함수를 완성해보세요.
int solution(vector<int> array) {
	int answer = 0;

	for (int n : array)
	{
		while (n >= 7)
		{
			if (n % 10 == 7)
			{
				answer++;
			}

			n /= 10;
		}
	}
	return answer;
}

// *** 공 던지기 ***
//머쓱이는 친구들과 동그랗게 서서 공 던지기 게임을 하고 있습니다.
//공은 1번부터 던지며 오른쪽으로 한 명을 건너뛰고 그다음 사람에게만 던질 수 있습니다.
//친구들의 번호가 들어있는 정수 배열 numbers와 정수 K가 주어질 때, k번째로 공을 던지는 사람의 번호는 무엇인지 return 하도록 solution 함수를 완성해보세요.
int solution(vector<int> numbers, int k) {
	int answer = 0;
	int len = numbers.size(); 
	int index = (k - 1) * 2; // k번째로 던지는 사람의 인덱스
	
	if (len > index)
	{
		// 던지는 사람의 index가 총 사람 수 보다 작을 경우
		answer = numbers[index];
	}
	else
	{
		// 던지는 사람의 index가 총 사람의 수보다 클 경우 전체 사람 수(길이)의 남은 인덱스
		answer = numbers[index % len];
	}

	return answer;
}

// *** 영어가 싫어요 ***
//영어가 싫은 머쓱이는 영어로 표기되어있는 숫자를 수로 바꾸려고 합니다.
//문자열 numbers가 매개변수로 주어질 때, numbers를 정수로 바꿔 return 하도록 solution 함수를 완성해 주세요.
//long long solution(string numbers) {
//	// 영어 숫자 배열 생성 ( 비교용 ) 
//	vector<string> v = { "zero","one","two","three","four","five","six","seven","eight","nine" };
//	long long answer = 0;
//
//	// numbers의 문자열이 없어질때 까지 반복
//	while (numbers.length() > 0)
//	{
//		for (int i = 0; i < v.size(); i++)
//		{
//			// 반복문을 통해 숫자 검열
//			if (numbers.substr(0, v[i].length()) == v[i])
//			{
//				// 10씩 곱해가며 자릿수 늘리기
//				answer = answer * 10 + i;
//
//				// 숫자를 찾았다면 찾은 문자열의 수만큼 잘라 numbers에 저장
//				numbers = numbers.substr(v[i].length());
//			}
//		}
//	}
//	
//	return answer;
//}

//컨트롤 제트
//숫자와 "Z"가 공백으로 구분되어 담긴 문자열이 주어집니다.문자열에 있는 숫자를 차례대로 더하려고 합니다.
//이 때 "Z"가 나오면 바로 전에 더했던 숫자를 뺀다는 뜻입니다.숫자와 "Z"로 이루어진 문자열 s가 주어질 때, 머쓱이가 구한 값을 return 하도록 solution 함수를 완성해보세요.
int solution(string s) {
	int answer = 0;
	int num = 0;

	istringstream iss(s);		// istringstram은 공백을 구분자로 문자열을 추출
	vector<string> v;
	string str;

	// 문자열을 배열에 넣기
	while (iss >> str)
	{
		v.push_back(str);
	}

	for (auto c : v)
	{
		// Z가 나오기전까지 숫자들을 합한다.
		if (c != "Z")
		{
			answer += stoi(c);
			num = stoi(c);
		}
		// Z가 나오면 이전에 합한 수를 뺀다.
		else
		{
			answer -= num;
		}
	}

	return answer;
}
void main()
{
	/*vector<int> array = { 1, 2, 3 };
	solution(array,3);
	*/

	solution("10 Z 20 Z");
	return;
}
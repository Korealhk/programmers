
#include "main.h"

// *** 잘라서 배열로 저장하기 ***
//문자열 my_str과 n이 매개변수로 주어질 때, my_str을 길이 n씩 잘라서 저장한 배열을 return하도록 solution 함수를 완성해주세요.
vector<string> solution(string my_str, int n) {
	vector<string> answer;

	for (int i = 0; i < my_str.length(); i += n)
	{
		answer.push_back(my_str.substr(i, n));
	}
	
	return answer;
}

// *** 문자열 계산하기 ***
//my_string은 "3 + 5"처럼 문자열로 된 수식입니다.문자열 my_string이 매개변수로 주어질 때, 수식을 계산한 값을 return 하는 solution 함수를 완성해주세요.
int solution(string my_string) {
	int answer = 0;

	istringstream iss(my_string);
	vector<string> v;
	string str;

	while (iss >> str)
	{
		v.push_back(str);
	}

	answer = stoi(v[0]);

	for (int i = 1; i < v.size();i+=2)
	{
		if (v[i] == "+")
		{
			answer = answer + stoi(v[i + 1]);
		}
		else if (v[i] == "-")
		{
			answer = answer - stoi(v[i + 1]);
			
		}

	}

	return answer;
}


void main()
{
	/*vector<int> array = { 1, 2, 3 };
	solution(array,3);
	*/

	solution("3 + 4 - -4 + 2 + 1 + -6 + 3 - 3");
	return;
}

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

//구슬을 나누는 경우의 수
//머쓱이는 구슬을 친구들에게 나누어주려고 합니다.구슬은 모두 다르게 생겼습니다.
//머쓱이가 갖고 있는 구슬의 개수 balls와 친구들에게 나누어 줄 구슬 개수 share이 매개변수로 주어질 때, 
//balls개의 구슬 중 share개의 구슬을 고르는 가능한 모든 경우의 수를 return 하는 solution 함수를 완성해주세요.
int solution(int balls, int share) {

	if (balls > 30 || share > balls)
	{
		return 1;
	}

	int answer = 0;
	long double n = 1, m = 1, s = 1;

	for (int i = 1; i <= balls; i++)
	{
		n *= i;
	}

	for (int j = 1; j <= share; j++)
	{
		m *= j;
	}

	for (int k = 1; k <= balls - share; k++)
	{
		s *= k;
	}

	answer = n / (m*s);

	return answer;
}

// *** 삼각형의 완성조건(2) ***
//선분 세 개로 삼각형을 만들기 위해서는 다음과 같은 조건을 만족해야 합니다.
//
//가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 합니다.
//삼각형의 두 변의 길이가 담긴 배열 sides이 매개변수로 주어집니다.나머지 한 변이 될 수 있는 정수의 개수를 return하도록 solution 함수를 완성해주세요.

int solution(vector<int> sides) {
	int answer = 0;
	
	if (sides[0] > sides[1])
	{
		swap(sides[0], sides[1]);
	}

	answer = sides[0] + (sides[0] - 1);

	return answer;
}



void main()
{
	vector<int> array = {1,2};

	cout << solution(array) << endl;
	return;
}
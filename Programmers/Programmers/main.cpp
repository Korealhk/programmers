
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
	
	// 변의 길이로 변 정렬.
	if (sides[0] > sides[1])
	{
		swap(sides[0], sides[1]);
	}


	answer = sides[0] + (sides[0] - 1);

	return answer;
}

// *** 외계어 사전 ***
//PROGRAMMERS - 962 행성에 불시착한 우주비행사 머쓱이는 외계행성의 언어를 공부하려고 합니다.
//알파벳이 담긴 배열 spell과 외계어 사전 dic이 매개변수로 주어집니다.
//spell에 담긴 알파벳을 한번씩만 모두 사용한 단어가 dic에 존재한다면 1, 존재하지 않는다면 2를 return하도록 solution 함수를 완성해주세요.외계어 사전
int solution(vector<string> spell, vector<string> dic) {
	int answer = 2;
	bool check = false;

	string str = "";
	vector<string> v;

	for (int i = 0; i < spell.size(); i++)
	{
		str += spell[i];
	}

	sort(str.begin(), str.end());

	do {
		v.push_back(str);
	} while (next_permutation(str.begin(), str.end()));

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < dic.size(); j++)
		{
			if (dic[j] == v[i])
			{
				answer = 1;
			}
		}
	}

	return answer;
}

// *** 캐릭터의 좌표 ***
//머쓱이는 RPG게임을 하고 있습니다.게임에는 up, down, left, right 방향키가 있으며 각 키를 누르면 위, 아래, 왼쪽, 오른쪽으로 한 칸씩 이동합니다.
//예를 들어[0, 0]에서 up을 누른다면 캐릭터의 좌표는[0, 1], down을 누른다면[0, -1], left를 누른다면[-1, 0], right를 누른다면[1, 0]입니다.
//머쓱이가 입력한 방향키의 배열 keyinput와 맵의 크기 board이 매개변수로 주어집니다.
//캐릭터는 항상[0, 0]에서 시작할 때 키 입력이 모두 끝난 뒤에 캐릭터의 좌표[x, y]를 return하도록 solution 함수를 완성해주세요.
//
//[0, 0]은 board의 정 중앙에 위치합니다.예를 들어 board의 가로 크기가 9라면 캐릭터는 왼쪽으로 최대[-4, 0]까지 오른쪽으로 최대[4, 0]까지 이동할 수 있습니다.

vector<int> solution(vector<string> keyinput, vector<int> board) {
	vector<int> answer = { 0,0 };

	board[0] = board[0] / 2;
	board[1] = board[1] / 2;

	for (int i = 0; i < keyinput.size(); i++)
	{
		if (keyinput[i].compare("up") == 0)
		{
			if (answer[1] < board[1])
			{
				answer[1] += 1;
			}
		}
		else if (keyinput[i].compare("down") == 0)
		{
			if (answer[1] > -board[1])
			{
				answer[1] -= 1;
			}
		}
		else if (keyinput[i].compare("right") == 0)
		{
			if (answer[0] < board[0])
			{
				answer[0] += 1;
			}
		}
		else if (keyinput[i].compare("left") == 0)
		{
			if (answer[0] > -board[0])
			{
				answer[0] -= 1;
			}
		}
	}
	return answer;
}

void main()
{
	vector<string> array = {"left","right","up","down","down"};
	vector<int> str = { 5,7 };

	solution(array, str);
	return;
}
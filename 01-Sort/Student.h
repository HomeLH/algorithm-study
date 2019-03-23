#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	int score;
	bool operator<(const Student &otherStudent) {
		return score != otherStudent.score  ? score < otherStudent.score : name < otherStudent.name;
	}
	// 友元函数，让 << 能访问 student的成员，非友元的话就是 student << out 不符合书写习惯
	friend ostream& operator<<(ostream &os, const Student &student) {
		os << "Student:" << student.name << " " << student.score;
		return os;
	}
};


#pragma once
#include<iostream>
#include <cstring>
using namespace std;

class Student
{
	string name;
	float gradeMath;
	float gradeEnglish;
	float gradeHistory;

public:

	string SetName(const string& name);
	bool SetMath(float grade);
	bool SetEnglish(float grade);
	bool SetHistory(float grade);

	string GetName();
	float GetMath();
	float GetEnglish();
	float GetHistory();
	float GetAverageGrade();

	int CompareByName(Student& s1, Student& s2);
	int CompareByMath(Student& s1, Student& s2);
	int CompareByEnglish(Student& s1, Student& s2);
	int CompareByHistory(Student& s1, Student& s2);
	int CompareByAverage(Student& s1, Student& s2);
};


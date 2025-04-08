#include "Student.h"

string Student::SetName(const string& name)
{
	this->name = name;
	return name;
}

bool Student::SetMath(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		gradeMath = grade;
		return true;
	}

	return false;
}

bool Student::SetEnglish(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		gradeEnglish = grade;
		return true;
	}

	return false;
}

bool Student::SetHistory(float grade)
{
	if (grade >= 1.0f && grade <= 10.0f)
	{
		gradeHistory = grade;
		return true;
	}

	return false;
}

string Student::GetName()
{
	return name;
}

float Student::GetMath()
{
	return gradeMath;
}

float Student::GetEnglish()
{
	return gradeEnglish;
}

float Student::GetHistory()
{
	return gradeHistory;
}

float Student::GetAverageGrade()
{
	return (gradeMath + gradeEnglish + gradeHistory)/3.0f;
}

int Student::CompareByName(Student& s1, Student& s2)
{
	if (s1.GetName() > s2.GetName())
	{
		return 1;
	}
	
	if (s1.GetName() < s2.GetName())
	{
		return -1;
	}

	return 0;
}

int Student::CompareByMath(Student& s1, Student& s2)
{
	if (s1.GetMath() > s2.GetMath())
	{
		return 1;
	}

	if (s1.GetMath() < s2.GetMath())
	{
		return -1;
	}

	return 0;
}

int Student::CompareByEnglish(Student& s1, Student& s2)
{
	if (s1.GetEnglish() > s2.GetEnglish())
	{
		return 1;
	}

	if (s1.GetEnglish() < s2.GetEnglish())
	{
		return -1;
	}

	return 0;
}

int Student::CompareByHistory(Student& s1, Student& s2)
{
	if (s1.GetHistory() > s2.GetHistory())
	{
		return 1;
	}

	if (s1.GetHistory() < s2.GetHistory())
	{
		return -1;
	}

	return 0;
}



int Student::CompareByAverage(Student& s1, Student& s2)
{
	if (s1.GetAverageGrade() > s2.GetAverageGrade())
	{
		return 1;
	}

	if (s1.GetAverageGrade() < s2.GetAverageGrade())
	{
		return -1;
	}

	return 0;
}







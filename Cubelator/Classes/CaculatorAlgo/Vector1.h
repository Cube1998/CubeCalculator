#pragma once
class Vector1
{
public:
	Vector1();
	~Vector1();
	Vector1(Vector1& vec);
	Vector1(int d, int * elem);
	void Add(const Vector1 vec);
	void Minus(const Vector1 vec);
	void print();
    std::string getVecInStr();
	double getCosAngle(Vector1 &vec);//求取向量夹角的余弦值
private:
	int * _Elem;
	int dimension;//维数
};


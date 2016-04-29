#ifndef BIG_DATA_H
#define BIG_DATA_H
#include<string>
#include<iostream>
using namespace std;

#define UN_INT 0xcccccccccccccccc    //��ʼ��ֵ
#define MAX_INT64 0x7fffffffffffffff //64bitΪ�ɴ���������һ��long long��
#define MIN_INT64 0x8000000000000000 //64bitΪ�ɴ���С����

typedef long long INT64; 

class BigData
{
public:
	BigData(INT64 data = UN_INT); //ȱʡ����
	BigData(const char *pData);   //����

	BigData operator+(BigData& bigData);
	BigData operator-(const BigData& bigData);
	BigData operator*(const BigData& bigData);
	BigData operator/(const BigData& bigData);
	BigData operator%(const BigData& bigData);


//================================================
	bool operator<(const BigData& bigData);
	bool operator>(const BigData& bigData);
	bool operator==(const BigData& bigData);

//�������
	friend std::istream& operator>>(std::istream& _cin,BigData bigData);
	friend std::ostream& operator<<(std::ostream& _cout,const BigData& bigData);

	bool IsINT64Owerflow() const;



private:
	std::string Add(std::string left,std::string right);
	std::string Sub(std::string left,std::string right);
	std::string Mul(std::string left,std::string right);
	std::string Div(std::string left,std::string right);

	void INT64ToString();

	bool IsLeftStrBig(char *pLeft,size_t LSize,char *pRight,size_t RSize);
	char SubLoop(char *pLeft,size_t LSize,char *pRight,size_t RSize);
private:
	long long m_llValue;    //����װ��longlong��
	std::string m_strData;  //����װ���ַ�����  //Ҳ��ȫת���ַ����� ����Ч�ʵ�
};

#endif
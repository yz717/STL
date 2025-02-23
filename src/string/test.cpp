#include "String.h"

// ���Թ��캯��
void test1() {
	String s1;
	String s2("hello");

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// ���Կ������캯��
void test2() {
	String s1("hello");
	String s2(s1);

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// ���Ը�ֵ����������
void test3() {
	String s1("hello");
	String s2;
	s2 = s1;

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// ����+=���������
void test4() {
	String s1("hello");
	s1 += ' ';
	s1 += "world";

	cout << s1.c_str() << endl;
}

// ���Բ��뺯��
void test5() {
	String s1("hello");
	s1.insert(5, " world");
	s1.insert(0, "say ");

	cout << s1.c_str() << endl;
}

// ����ɾ������
void test6() {
	String s1("hello world");
	s1.erase(5, 6);
		cout << s1.c_str() << endl;
}

// ���Ե����ַ�����С
void test7() {
	String s1("hello");
	s1.resize(10, '!');
	cout << s1.c_str() << endl;
	s1.resize(2);
	cout << s1.c_str() << endl;
}

// ���Բ��Һ���
void test8() {
	String s1("hello world");
	cout << s1.find('o') << endl;
	cout << s1.find("world") << endl;
}

// �����������
void test9() {
	String s1;
	cin >> s1;
	cout << s1 << endl;
	String s2;
	getline(cin, s2);
	cout << s2 << endl;
}

// ���ԱȽ������
void test10() {
	String s1("hello");
	String s2("hello");
	String s3("world");
	cout << (s1 == s2) << endl;
	cout << (s1 == s3) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 != s3) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 < s3) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 > s3) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 <= s3) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 >= s3) << endl;
}


// ����[]�����
void test11() {
	String s("hello");
	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;
	cout << s[3] << endl;
	cout << s[4] << endl;
}

// ���Ե�����
void test12() {
	String s("hello");
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// ����Size��Length��Capacity����
void test13() {
	String s("hello");
	s += " world";
	cout << s.Size() << endl;
	cout << s.length() << endl;
	cout << s.Capacity() << endl;

}
int main() {
	return 0;
}
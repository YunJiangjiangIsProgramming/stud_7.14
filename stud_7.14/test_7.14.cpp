#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<vector>
#include <string>
#include <stdexcept>


using namespace std;
#include"Stack.h"
#include"Queue.h"

class Solution1 {
public:
    // ��֤ջ�����Ƿ���Ч
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        // ʹ��һ�������ջ��ģ������͵�������
        stack<int> st;

        // pushi �� popi �ֱ��� pushed �� popped ���������ָ��
        int pushi = 0;
        int popi = 0;

        // ���� pushed ���飬��ÿ��Ԫ������ģ��ջ��
        while (pushi < pushed.size())
        {
            st.push(pushed[pushi]); // ����ǰԪ������ջ��
            pushi++; // �ƶ��� pushed �������һ��Ԫ��

            // ��ģ��ջ��Ϊ�գ�����ջ��Ԫ�ص��� popped ���鵱ǰָ���Ԫ��ʱ��
            // ��������ջ��Ԫ�أ����ƶ��� popped �������һ��Ԫ��
            while (!st.empty() && st.top() == popped[popi])
            {
                st.pop(); // ��ջ�е���Ԫ��
                popi++; // �ƶ��� popped �������һ��Ԫ��
            }
        }

        // ���ģ��ջΪ�գ�˵�����е�Ԫ�ض�������ȷ��˳�򱻵��������� true
        // ����˵������Ԫ��û�б���ȷ���������� false
        return st.empty();
    }
};

class Solution2 {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (str[0])
                {
                case '+':
                    st.push(right + left);
                    break;
                case '-':
                    st.push(right - left);
                    break;
                case '*':
                    st.push(right * left);
                    break;
                case '/':
                    st.push(right / left);
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};

class Solution {
public:

    int evalRPN(std::vector<std::string>& tokens) {
        // ����һ��ջ���洢�м���
        std::stack<int> st;

        // �����沨�����ʽ�е�ÿ�����
        for (const auto& str : tokens) {
            // ��鵱ǰ����Ƿ�Ϊ�����
            if (isOperator(str)) {
                // ���ջ�е�Ԫ����������������ʽ��Ч
                if (st.size() < 2) {
                    throw std::invalid_argument("Invalid RPN expression: not enough operands");
                }
                // ȡ��ջ��������Ԫ����Ϊ������
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                // ���������������ִ����Ӧ�ļ���
                switch (str[0]) {
                case '+': // �ӷ�
                    st.push(left + right);
                    break;
                case '-': // ����
                    st.push(left - right);
                    break;
                case '*': // �˷�
                    st.push(left * right);
                    break;
                case '/': // ����
                    // ��������Ϊ��
                    if (right == 0) {
                        throw std::invalid_argument("Invalid RPN expression: division by zero");
                    }
                    st.push(left / right);
                    break;
                default: // �����������Ϸ�
                    throw std::invalid_argument("Invalid RPN expression: unknown operator");
                }
            }
            else {
                // �����ǰ��������֣�����ת��Ϊ������ѹ��ջ��
                st.push(std::stoi(str));
            }
        }

        // ����ڱ��������б�Ǻ�ջ�в�ֻʣ��һ��Ԫ�أ�����ʽ��Ч
        if (st.size() != 1) {
            throw std::invalid_argument("Invalid RPN expression: too many operands");
        }

        // ����ջ��Ԫ�أ���������
        return st.top();
    }

private:
    // �жϸ������ַ����Ƿ���һ�������
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
};

void test_stack()
{
    luow::stack<int, list<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
void test_queue()
{  luow::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (!q.empty())
	{
        cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

}


int main()
{
    test_stack();
    test_queue();

	return 0;
}
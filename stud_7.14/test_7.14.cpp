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
    // 验证栈操作是否有效
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        // 使用一个额外的栈来模拟推入和弹出操作
        stack<int> st;

        // pushi 和 popi 分别是 pushed 和 popped 数组的索引指针
        int pushi = 0;
        int popi = 0;

        // 遍历 pushed 数组，将每个元素推入模拟栈中
        while (pushi < pushed.size())
        {
            st.push(pushed[pushi]); // 将当前元素推入栈中
            pushi++; // 移动到 pushed 数组的下一个元素

            // 当模拟栈不为空，并且栈顶元素等于 popped 数组当前指向的元素时，
            // 持续弹出栈顶元素，并移动到 popped 数组的下一个元素
            while (!st.empty() && st.top() == popped[popi])
            {
                st.pop(); // 从栈中弹出元素
                popi++; // 移动到 popped 数组的下一个元素
            }
        }

        // 如果模拟栈为空，说明所有的元素都按照正确的顺序被弹出，返回 true
        // 否则，说明还有元素没有被正确弹出，返回 false
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
        // 创建一个栈来存储中间结果
        std::stack<int> st;

        // 遍历逆波兰表达式中的每个标记
        for (const auto& str : tokens) {
            // 检查当前标记是否为运算符
            if (isOperator(str)) {
                // 如果栈中的元素少于两个，则表达式无效
                if (st.size() < 2) {
                    throw std::invalid_argument("Invalid RPN expression: not enough operands");
                }
                // 取出栈顶的两个元素作为操作数
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                // 根据运算符的类型执行相应的计算
                switch (str[0]) {
                case '+': // 加法
                    st.push(left + right);
                    break;
                case '-': // 减法
                    st.push(left - right);
                    break;
                case '*': // 乘法
                    st.push(left * right);
                    break;
                case '/': // 除法
                    // 除数不能为零
                    if (right == 0) {
                        throw std::invalid_argument("Invalid RPN expression: division by zero");
                    }
                    st.push(left / right);
                    break;
                default: // 如果运算符不合法
                    throw std::invalid_argument("Invalid RPN expression: unknown operator");
                }
            }
            else {
                // 如果当前标记是数字，则将其转换为整数并压入栈中
                st.push(std::stoi(str));
            }
        }

        // 如果在遍历完所有标记后栈中不只剩下一个元素，则表达式无效
        if (st.size() != 1) {
            throw std::invalid_argument("Invalid RPN expression: too many operands");
        }

        // 返回栈顶元素，即计算结果
        return st.top();
    }

private:
    // 判断给定的字符串是否是一个运算符
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
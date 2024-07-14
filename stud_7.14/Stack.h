#pragma once
#include<list>
#include<vector>
#include<deque>

namespace luow
{
	template<class T,class Container = deque<T>>//ȱʡ��������deque
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
		T& top()
		{
			return _con.back();
		}


	private:
		Container _con;

	};

}

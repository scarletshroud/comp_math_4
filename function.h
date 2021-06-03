#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <functional>
#include <string>

class Function {
public:
	Function();
	Function(std::function<double(double)> f, const std::string str);
	~Function();

	std::function<double(double)> f();
	std::function<double(double)> df();
	std::function<double(double)> d2f();

	const std::string& str();

private:
	std::function<double(double)> m_f;
	std::function<double(double)> m_df;
	std::function<double(double)> m_d2f;

	std::string m_str;

};

#endif // !_FUNCTION_H_


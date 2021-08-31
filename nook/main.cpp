#include "../basic/basics.h"
#include "BookManager.h"
/*
瀚海

书单录入，书本数量，可用状态，owner（邮箱，借入，归还时间），

Query : getBookList(), getBookStatus(),
Action : 删 borrow(), 增 return(), 书目扩充 addNewBook(),

socket
flask

*/



double operator"" _mm(long double x) { return x / 1000; }

system_clock::time_point now; //only for test

char const* operator"" _r(char const* s)
{
	return s;
}
std::chrono::minutes operator""_heima(unsigned long long m) {   // 字面量运算符重载规定了参数类型只有几种
	std::cout << "执行了operator函数:" << m << std::endl;            // constexpr存在,没法运行这行代码
	return std::chrono::minutes(m);
}
using namespace std::chrono_literals;               // C++14才能用
//using namespace std::literals;                      // C++14才能用
//using namespace std::literals::chrono_literals;
int main() {

  BookManager::getInstance()->addNewBook("Effective Modern C++", "S C");

#if 0
	const std::chrono::minutes& duration = 24_heima;    // 24会传递给参数m

	std::cout << "输出:" << duration.count() << std::endl;
   // const std::chrono::duration<long double, std::ratio<60, 1>>& duration0 = std::literals::chrono_literals::operator ""min(123);
   // const std::chrono::duration<long double, std::ratio<60, 1>>& duration1 = std::literals::chrono_literals::operator ""min(123.0);

    //const std::chrono::duration<long double, std::ratio<60, 1>>& duration2 = std::literals::operator ""min(123.0);
    //const std::chrono::duration<long double, std::ratio<60, 1>>& duration3 = std::literals::chrono_literals::operator ""min(12.3);


    //--------------------------------------------------------------

        // 系统自带的min运算符
    123min;                        // C++14才能用

    const std::chrono::minutes& temp = 456min;
    std::cout << "消耗的时间5：" << 12min.count() << std::endl;
    123min.count();

#endif
//	system("pause");
}
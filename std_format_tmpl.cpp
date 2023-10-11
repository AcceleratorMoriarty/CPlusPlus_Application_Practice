// gcc v 13.2
// g++ -g -std=c++20 -O3 -flto
#include <iostream>
#include <format>

// C++语言小练习（1)
// 使用format输出

int main() {

    const double realValue = 3.1415926;
    const int intValue = 2346;

    // 1. 输出浮点数 realValue                                 // realValue = 3.1415926 
    std::cout << std::format("realValue = {}\n", realValue);
    // 2. realValue 小数点后取2位有效值                        // realValue = 3.14 
    std::cout << std::format("realValue = {:.2f}\n", realValue);
    // 3. realValue 小数点后取2位有效值，整数部分宽度为4位     // realValue =     3.14 
    std::cout << std::format("realValue = {:8.2f}\n", realValue);
    // 4. realValue 小数点后取2位有效值，整数部分宽度为4位，不足4位以0填充         // realValue = 00003.14 
    std::cout << std::format("realValue = {:08.2f}\n", realValue);
    // 5. realValue 整数部分1位，小数点后取2位有效值，总共8位，不足部分以0填充     // realValue = 3.140000 
    std::cout << std::format("realValue = {:.2f}{:04}\n", realValue, 0);
    std::cout << std::format("realValue = {:0<8.2f}\n", realValue);// 左对齐，其余以0填充
    // 6. realValue 带有符号位，小数点后取2位有效值，即： +3.14                    // realValue = +3.14 
    std::cout << std::format("realValue = {:+.2f}\n", realValue);
    // 7. 整型数，普通输出                                      // intValue = 2346 
    std::cout << std::format("intValue = {}\n", intValue);
    // 8. 整型数，按照16进制大写形式输出，                      // intValue = 92A 
    std::cout << std::format("intValue = {:X}\n", intValue);
    // 9. 整型数，按照16进制大写形式输出8位，不足8位部分以0填充     // intValue = 0000092A 
    std::cout << std::format("intValue = {:08X}\n", intValue);
    // 10. 整型数，按照16进制小写形式输出，总长8位，添加0x标记     // intValue = 0x00092a 
    std::cout << std::format("intValue = {:#08x}\n", intValue);
    // 11. 整型数，按照16进制大写输出，添加0X标记，数字部分为8位，不足部分以0填充     // intValue = 0X0000092A 
    std::cout << std::format("intValue = {:#010X}\n", intValue);
    // 12. 整型数，按照16进制大写输出，添加0X标记，宽度10位，左对齐     // intValue = 0X92A      
    std::cout << std::format("intValue = {:<#10X}\n", intValue);
    // 13. 整型数，按照16进制大写输出，添加0X标记，宽度10位，右对齐     // intValue =      0X92A 
    std::cout << std::format("intValue = {:>#10X}\n", intValue);
    // 14. 整型数，输出大括号，10位宽度，不足部分前方补0                // intValue = {0000002346} 
    std::cout << std::format("intValue = {{{:010}}}\n", intValue);
    // 15. 使用索引，请将\"your_name\"/\"your_num\"替换为自己的学号和姓名 
    std::cout << std::format(" -> good job: 学号:{1}, 姓名:{0} \n", "徐卉垚", "202121018094");
    return 0;
}

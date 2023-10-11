// gcc v 13.2
// g++ -g -std=c++20 -O3 -flto
#include <algorithm>
#include <format>
#include <iostream>
#include <ranges>
#include <vector>

// C++语言小练习（2)
// 基于范围的for循环和lambda函数

// 运算符重载，可以使用std::cout<<vec的形式输出 vector 对象
std::ostream& operator<<(std::ostream& os, const std::vector<int> vec);

int main() {
    // 创建vector，注意这里使用了lambda函数： [](){return std::rand()%100;}
    std::srand(2023);
    std::vector<int> values(20);  // 需要包含头文件 #include <vector>
    // 生成随机数，需要包含头文件 #include <algorithm>
    std::generate(values.begin(), values.end(),
        []() { return std::rand() % 100; });
    // 结果： values = {30 70 55 28 10 72 44 95 30 85 59 52 8 20 18 91 39 15 6
    // 60 };

    // 1. 使用std::cout 输出values
    // 输出： 30 70 55 28 10 72 44 95 30 85 59 52 8 20 18 91 39 15 6 60
    std::cout << std::format("打印每个元素值:\n");
    std::cout << values << std::endl;
    /*std::cout << "请替换该段代码实现上述输出" << std::endl;*/

    // 2. 使用传统for循环遍历数组，打印每个元素的2倍值
    // 输出： 60 140 110 56 20 144 88 190 60 170 118 104 16 40 36 182 78 30 12
    // 120 std::cout<<std::format("{}\n",values);
    std::cout << std::format("使用传统for循环遍历数组, 打印每个元素的2倍值:\n");
    for (int i = 0; i < values.size(); i++) {
        // "请编写该段代码实现上述输出"
        std::cout << values[i]*2<<" ";
    }
    std::cout << std::endl;

    // 3. 使用基于范围的for循环遍历数组，打印每个元素的2倍值
    // 输出：60 140 110 56 20 144 88 190 60 170 118 104 16 40 36 182 78 30 12
    // 120
    std::cout << std::format(
        "使用基于范围的for循环遍历数组, 打印每个元素的2倍值:\n");
    for (const auto& v : values) {
        // "请编写该段代码实现上述输出"
        std::cout << v * 2 << " ";
    }
    std::cout << std::endl;

    // 4. 使用std::sort函数排序
    std::vector<int> tobesorted;
    // 思考，为什么不使用 tobesorted=value 进行直接赋值？
    //tobesorted = values;         // 注意，此处不宜直接赋值

    
    // 答：assign 擦除向量中的所有现有元素；然后，将指定范围内的元素从原始向量插入某个向量中，
    // 或者将新的指定值元素的副本插入某个向量。从结果而言，重载操作符 =和assign方法一样，
    // 都是深拷贝，所以结果是不受影响的。从内存角度，如果重载=号，values的管理内存会被剥
    // 夺，只能tobesorted来管理。
    tobesorted.assign(values.begin(), values.end());

    // 输出待排序数组和递减排序后数组
    std::cout << "待排序数组: \n -> " << tobesorted << std::endl;
    std::sort(tobesorted.begin(), tobesorted.end());
    std::cout << "递增排序后数组: \n -> " << tobesorted << std::endl;

    tobesorted.assign(values.begin(), values.end());
    // 5. 请仿照上述代码，输出待排序数组和递增排序后数组
    std::cout << "待排序数组: \n -> " << tobesorted << std::endl;
    // std::sort(" 请编写该段代码实现递减排序输出 ");
    std::sort(tobesorted.rbegin(), tobesorted.rend());
    std::cout << "递减排序后数组: \n -> " << tobesorted << std::endl;

    // 6. 使用std::ranges 排序, 需要包含头文件 #include <ranges>
    namespace rng = std::ranges;
    tobesorted.assign(values.begin(), values.end());
    std::cout << "待排序数组: \n -> " << tobesorted << std::endl;
    rng::sort(tobesorted);
    std::cout << "递增排序后数组: \n -> " << tobesorted << std::endl;
    // 7. 使用std::ranges 排序，递减排序
    tobesorted.assign(values.begin(), values.end());
    std::cout << "待排序数组: \n -> " << tobesorted << std::endl;
    // rng::sort(" 请编写该段代码实现递减排序输出 ");
    //  using a standard library
    //rng::sort(tobesorted,rng::greater());
    //   using a standard library
    rng::sort(tobesorted, [](int a, int b) { return a > b; });
    std::cout << "递减排序后数组: \n -> " << tobesorted << std::endl;

    // 8. 请将\"your_name\"/\"your_num\"替换为自己的学号和姓名
    std::cout << std::format(" ****** good job: 学号:{1}, 姓名:{0} ******\n",
        "徐卉垚", "202121018094");

    return 0;
}

// 运算符重载，可以使用std::cout<<vec的形式输出 vector 对象
std::ostream& operator<<(std::ostream& os, const std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    return os;
}
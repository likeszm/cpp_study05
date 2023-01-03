/*
* 名称：循环测试
* 
*/

#include <iostream>

void while_test(void);
void do_while_test(void);
void for_test(void);
void iteration_test(void);
void nest_test(void);
void break_test(void);
void continue_test(void);
void goto_test(void);


int main()
{
    //while_test();
    //do_while_test();
    //for_test();
    //iteration_test();
    //nest_test();
    //break_test();
    //continue_test();
    //goto_test();


    std::cout << "\n测试完成\n";
    return 0;
}

void while_test(void)
{
    int count;
    std::cout << "请输入while循环次数：";
    std::cin >> count;
    while (count) std::cout << "正在循环，count = " << count-- << std::endl;
}

void do_while_test(void)
{
    int count;
    std::cout << "请输入do_while循环次数：";
    std::cin >> count;
    do {
        std::cout << "正在循环，count = " << count << std::endl;
        count--;
    } while (count > 0);
}

void for_test(void)
{
    int count;
    std::cout << "请输入for循环次数：";
    std::cin >> count;
    for (int i = count; i > 0; i--)
    {
        std::cout << "正在循环，i = " << i << std::endl;
    }
}

void iteration_test(void)
{
#if 1
    int list[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
    {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
    std::cout << "进行迭代" << std::endl;
    for (auto & x : list)
    {
        x = x * 2;
    }
    for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
    {
        std::cout << "list[" << i << "] = " << list[i] << std::endl;
    }
#else

    for (int x : {9, 8, 7, 6, 5, 4, 3, 2, 1, 0})
    {
        std::cout << "正在迭代，值为：" << x << std::endl;
    }

#endif

    
}

void nest_test(void)
{
    for (int x = 1; x < 10; x++)
    {
        for (int y = 1; y <= x; y++)
        {
            std::cout << y << "*" << x << "=" << x * y << "\t";
        }
        std::cout << std::endl;
    }
}

void break_test(void)
{
    int count = 0;
    std::cout << "期望的循环次数：" << std::endl;
    std::cin >> count;
    while (count <= 0)
    {
        std::cout << "请重新输入，要求大于0：" << std::endl;
        std::cin >> count;
    }

#define BREAK_TYPE 3
#if BREAK_TYPE == 1

    int i = 0;
    while (1)
    {
        i++;
        std::cout << "while语句已经循环：" << i << "次" << std::endl;
        if (i == count)break;
    }
    std::cout << "成功通过break语句退出" << std::endl;

#elif BREAK_TYPE == 2

    int i = 0;
    do {
        i++;
        std::cout << "do_while语句已经循环：" << i << "次" << std::endl;
        if (i == count)break;
    } while (1);
    std::cout << "成功通过break语句退出" << std::endl;

#elif BREAK_TYPE == 3

    for (int i = 1;; i++)
    {
        std::cout << "for语句已经循环：" << i << "次" << std::endl;
        if (i == count)break;
    }
    std::cout << "成功通过break语句退出" << std::endl;

#else 
#error 'BREAK_TYPE' 数值非法!
#endif

}

void continue_test(void)
{
    int t = 0;
    std::cout << "请输入要跳过的值：" << std::endl;
    std::cin >> t;
    while (t < 0 || t>10)
    {
        std::cout << "请重新输入，范围0-10" << std::endl;
        std::cin >> t;
    }

#define CONTINUE_TYPE 3
#if CONTINUE_TYPE == 1

    int i = -1;
    while (++i <= 10)
    {
        if (i == t)
        {
            std::cout << std::endl;
            continue;
        }

        std::cout << "while中，现在 i = " << i << std::endl;
    }

#elif CONTINUE_TYPE == 2

    int i = 0;
    do
    {
        if (i == t)
        {
            std::cout << std::endl;
            continue;
        }
        std::cout << "do_while中，现在 i = " << i << std::endl;
    } while (++i <= 10);

#elif CONTINUE_TYPE == 3 

    for (int i = 0; i <= 10; i++)
    {
        if (i == t)
        {
            std::cout << std::endl;
            continue;
        }
        std::cout << "for中，现在 i = " << i << std::endl;
    }

#else 
#error "CONTINUE_TYPE" 数值非法!
#endif

}

void goto_test(void)
{
#define GOTO_TEST 2
 /*
 * 1、利用goto构造循环结构
 * 2、利用goto跳出嵌套循环
 */

    std::cout << "希望循坏的次数：" << std::endl;
    int count = 0;
    std::cin >> count;

#if GOTO_TEST == 1

    int i = 0;

    sign:

    i++;
    std::cout << "现在计数值为：" << i << std::endl;
    if ( i == count )
    {
        ;
    }
    else
    {
        if( count ) //防止输入0死循环
        goto sign;  //由于无论如何前面的代码至少运行一次，所以只能实现do_while的效果
    }

#elif GOTO_TEST == 2

    int i = 0;

    while (1)
    {
        do
        {
            for (;;)
            {
                if (i == count) goto stop;
                std::cout << "已循环 " << ++i << "次" << std::endl;
            }
        } while (1);
    }
    stop:
    std::cout << "成功跳出嵌套循环" << std::endl;

#else
#error "GOTO_TEST" 数值非法!
#endif 

}
#pragma once

#include <iostream>
#include <cstdlib>
// 1. 본인이름학번의 네임스페이스
// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 1234567일 경우 KimPro1234567

namespace kwonyonje2649061
{
// -네임스페이스 지정자 예: std::cout << "Enter your id: ";

// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴
    class dayOfYear
    {
        int month{};
        int day{};
        void testMonth()
        {
            if ((month<1)||(month>12))
            {
                std::cout << "Illegal month value!\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if ((day<1)||(day>31))
            {
                std::cout << "Illegal day value!\n";
                std::exit(1);
            }
        }
    public:
        dayOfYear( int monthvalue=1, int dayvalue=1 ):month{monthvalue}, day{dayvalue}
        {
            testMonth();
            testDay();
        }

        void input()
        {
            std::cout << "Enter month as a number: ";
            std::cin >> month; testMonth();
            std::cout << "Enter day of the month: ";
            std::cin >> day; testDay();
        }
        void setMonth(int m) {month = m; testMonth();}
        void setDay(int d) {day = d; testDay();}
        void print() const
        {
            std::cout << month << "/" << day <<std::endl;
        }
        int getMonth() const { return month; }
        int getDay() const { return day; }

// -멤버함수로 전위증가연산자, 후위증가연산자 정의
        dayOfYear operator ++()
        {
            ++day;
            if (day>31)
            {
                ++month;
                if (month>12)
                    month-=12;
                day-=31;
            }
            return dayOfYear{month, day};
        } 

        dayOfYear operator ++(int)
        {
            dayOfYear temp{month, day};
            ++day;
            if (day>31)
            {
                ++month;
                if (month>12)
                    month-=12;
                day-=31;
            }
            return temp;
        } 
    //intpair로 리턴하면 month에도 +1이 되어 이상함.
    // 1월 32일이 아닌 2월 1일로 고려하도록 추가적인 함수를 만들어야 한다. 

// -프렌드함수로서 입력연산자 >>, 출력연산자 <<, 이항연산자 ==, 이항연산자 + 정의
        friend std::istream& operator>>(std::istream& is, dayOfYear& d)
        {
            std::cout << "Enter month as a number: ";
            is >> d.month; d.testMonth();
            std::cout << "Enter day of the month: ";
            is >> d.day; d.testDay();
            return is;
        }
        friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
        {
            os << d.month << "/" << d.day <<std::endl;
            return os;
        }
        friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d2.day == d2.day;
        }
        friend dayOfYear operator +(const dayOfYear& d1, const dayOfYear& d2)
        {
            return dayOfYear{d1.month + d2.month, d1.day + d2.day};
        }
    };

}
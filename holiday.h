#pragma once
#include "dayOfYear.h"
#include <string>

namespace kwonyonje2649061
{
    class holiday
    {
        std::string name;
        dayOfYear d;
        bool parkingEnforcement{};
    public:
         holiday(const std::string& n = "no name yet", dayOfYear d0 = dayOfYear{1,1}, bool p0 = false): name{n}, d{d0}, parkingEnforcement{p0}
         {}
         void print() const
         {
            std::cout << name <<" : ";
            d.print(); 
            if (parkingEnforcement)
                std::cout << "parking laws will be enforced.\n";
            else
                std::cout << "parking laws will not be enforced.\n";
         }
        friend std::ostream& operator<< (std::ostream& os, const holiday& h)
        {
            os << h.name << " : ";
            os << h.d;
            if (h.parkingEnforcement)
                os << "parking laws will not be enforced.\n";
            return os;
        }

         void input()
         {
            std::cout << "Enter holiday name: ";
            std::getline(std::cin >> std::ws , name);
            d.input();
            std::cout << "enter parking law enforcement: (1(true) or 0(false))";
            std::cin >> parkingEnforcement;
         }
         friend std::istream& operator>>(std::istream& is, holiday& h)
         {
            std::cout<< "enter holiday name: ";
            std::getline(is >> std::ws, h.name);
            is >> h.d;
            std::cout<< "enter parking law enforcement: ";
            is >> h.parkingEnforcement;
            return is;
         }
         const std::string& getName() {const return name};
         void setName(const std::string& n) {name=n};
         const dayOfYear& getD() const { return d; }
         void setD(const dayOfYear& a) { d=a; }
         void setparkingEnforcement(bool p) {parkingEnforcement = p};
    };
}

// 1의 본인이름학번의 네임스페이스 안에 클래스2를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언: 클래스1형 객체, 그 외 멤버변수 1개 이상
// public 멤버함수 인라인으로 정의
// -생성자: 모든 멤버변수 초기화, 기본값 설정
// -print: 표준스트림출력으로 멤버변수들 출력
// -클래스1형 객체의 접근함수를 참조형식으로 구현
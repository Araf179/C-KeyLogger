#ifndef HELPER_H
#define HELPER_H
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>

namespace Helper{
    template <class T> //functions will take any type
    std::string ToString(const T &); //reference it by address
     //Structs are user defined types, Very similar to classes except everything is public;
    struct DateTime
    {
        DateTime(){
            time_t ms; //take system time and store it in ms
            time(&ms);
            struct tm *info = localtime(&ms); //Point to the returned value
            D = info->tm_mday; //access indirectly attribute tm_mday from struct DateTime
            m = info->tm_mon + 1; //Month it starts from zero which is why we add 1;
            y = 1900 + info->tm_year; // Year begins from 1900
            M = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S){}
        DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0){}

        DateTime Now() const {
            return DateTime();
        }

        int D, m, y, H, M, S;

        std::string GetDateString() const {
            return std::string(D < 10 ? "0" : "") + ToString(D) +
                   std::string(m < 10 ? ".0": ".") + ToString(m) + "." +
                   ToString(y);
        }
        //seperator
        std::string GetTimeString(const std::string &sep = ":"){
            return std::string(H < 10 ? "0" : "") + ToString(H) + sep +
                   std::string(M < 10 ? "0" : "") + ToString(M) + sep +
                   std::string(M < 10 ? sep : "") + ToString(S);
        }
        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            //return GetDateString() + " " + GetTimeString(sep);
            return "";
        }

    };

    template <class T>

    std::string ToString(const T &e){
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog(const std::string &s){
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() << "]" <<
        "\n" << s << std::endl << "\n";
        file.close();
    }
};

#endif // HELPER_H

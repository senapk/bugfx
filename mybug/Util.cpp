
#include <ctime>
#include <cstdlib>
#include <cstdarg> //va_list
#include <cstdio> //vsprintf
#include <sys/time.h> //gettimeofday timeval
#include <string>

#include "Util.h"

long Timer::getTimeNow(){
    struct timeval tv;
    gettimeofday(&tv, 0);
    return  tv.tv_sec*1000 + tv.tv_usec/1000;
}

Timer::Timer(){
    last = getTimeNow();
}
void Timer::update(){
    last = getTimeNow();
}
bool Timer::hasPassed(int msec){
    long now = getTimeNow();
    if((now - last) > msec)
        return true;
    return false;
}
long Timer::howLong(){
    return getTimeNow() - last;
}

namespace Util{
    std::string str(const char *format, ...){
        char str[1000];
        va_list args;
        va_start( args, format );
        vsprintf(str, format, args);
        va_end( args );
        std::string s(str);
        return s;
    }

    void sleep(int msec){
        struct timespec interval;
        struct timespec remainder;
        interval.tv_sec = msec / 1000;
        interval.tv_nsec = (msec % 1000) * (1000 * 1000);
        nanosleep(&interval, &remainder) ;
    }

    void srand(){
        std::srand(time(NULL));
    }

    int rand(){
        return std::rand();
    }
}

namespace Math{
    double calcDistance(sf::Vector2f a, sf::Vector2f b) {
        return std::sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
    }

    double calcAngle(sf::Vector2f a, sf::Vector2f b) {
        return rad2deg(atan((b.y - a.y)/(a.x - b.x)) + PI);
    }

    sf::Vector2f rotatePoint(sf::Vector2f a, sf::Vector2f b, double degrees) {
        sf::Vector2f c;
        double angle = (-1) * deg2rad(degrees);
        c.x = (b.x - a.x)*cos(angle) - (b.y - a.y)*sin(angle) + a.x;
        c.y = (b.y - a.y)*cos(angle) + (b.x - a.x)*sin(angle) + a.y;
        return c;
    }

    double sf2cart(double angle)
    {
        if (angle < 0){
            angle *= -1;
            angle = std::fmod(angle, 360);
            angle = 360 - angle;
        }
        if(angle < 90 )
            return 90 - angle;
        return (-1 * (angle - 90));
    }

}

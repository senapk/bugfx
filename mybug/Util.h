#ifndef UTIL_H
#define UTIL_H

#include <sys/time.h>
#include <string>

class Timer{
private:
    long last; //ultima medicao realizada
public:
    Timer();
    static long getTimeNow();
    void update();
    bool hasPassed(int msec);
    long howLong();
};

namespace Util{
    void srand();
    int  rand();
    void sleep(int msec);
    std::string str(const char * format, ...);
};

#include <cmath>
#include <SFML/System/Vector2.hpp>

namespace Math{
    const long long PI = 3.14159265358979323846;

    inline double deg2rad(double angle){ return (angle * (PI / 180.0)); }
    inline double rad2deg(double radians){ return (radians * (180.0 / PI)); }
    inline double dsin(double degrees){ return std::sin(deg2rad(degrees)); }
    inline double dcos(double degrees){ return std::cos(deg2rad(degrees)); }
    inline double dtan(double degrees){ return std::tan(deg2rad(degrees)); }

    /* Converte angulo do modelo sfml para modelo cartesiano */
    double sf2cart(double angle);

    /* Calcula a distancia entre os pontos a e b*/
    double calcDistance(sf::Vector2f a, sf::Vector2f b);

    /* Return the angle in degrees from a to b */
    double calcAngle(sf::Vector2f a, sf::Vector2f b);

    /* Retorna o ponto b rotacionado de degrees graus em relação ao ponto a*/
    sf::Vector2f rotatePoint(sf::Vector2f a, sf::Vector2f b, double degrees);
}


#endif // UTIL_H
